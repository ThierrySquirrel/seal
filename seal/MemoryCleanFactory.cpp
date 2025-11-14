/**
 * Copyright 2025/11/14 ThierrySquirrel
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#include "pch.h"
#include "MemoryCleanFactory.h"

 /**
 * @file: MemoryCleanFactory.cpp
 * @brief: C++20
 *
 * @authors ThierrySquirrel
 * @date 2025/11/14
 **/

void MemoryCleanFactory::memoryClean() {
    HANDLE thisProcessHandle;
    PROCESSENTRY32 thisProcessentry;

    thisProcessentry.dwSize = sizeof(PROCESSENTRY32);
    thisProcessHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    Process32First(thisProcessHandle, &thisProcessentry);

    bool nextProcess = true;

    while (nextProcess) {

        HANDLE allAccessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, thisProcessentry.th32ProcessID);

        EmptyWorkingSet(allAccessHandle);
        CloseHandle(allAccessHandle);

        nextProcess = Process32Next(thisProcessHandle, &thisProcessentry);
    }

    CloseHandle(thisProcessHandle);

}