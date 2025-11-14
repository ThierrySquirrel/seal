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
#include "ControlTextFactory.h"

 /**
  * @file: ControlTextFactory.cpp
  * @brief: C++20
  *
  * @authors ThierrySquirrel
  * @date 2025/11/14
  **/

std::wstring ControlTextFactory::getTotalMemory() {
    
    MemoryEntity memoryEntity = MemoryEntityBuildFactory::createMemoryInfo();
    int memory = memoryEntity.getAllMemory();

    std::wstring totalMemory = ControlTextFactoryConstant::showTotalMemory();
    totalMemory += std::to_wstring(memory);
    return totalMemory;
}

std::wstring ControlTextFactory::getUserMemory() {
    int memory = ControlTextFactory::getUserMemoryInt();
    std::wstring userMemory = ControlTextFactoryConstant::showUsedMemory();
    userMemory += std::to_wstring(memory);
    return userMemory;
}


std::wstring ControlTextFactory::getClearedMemory() {
    std::wstring  clearedMemory = ControlTextFactoryConstant::showClearedMemory();
    int memory = ControlTextContainer::getClearedMemory();

    clearedMemory += std::to_wstring(memory);
    return clearedMemory;
}


std::wstring ControlTextFactory::getVersion() {
    return ControlTextFactoryConstant::showVersion();
}

int ControlTextFactory::getUserMemoryInt() {
    return MemoryEntityBuildFactory::createMemoryInfo().getUsedMemory();
}