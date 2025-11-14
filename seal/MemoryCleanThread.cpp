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
#include "MemoryCleanThread.h"

 /**
 * @file: MemoryCleanThread.cpp
 * @brief: C++20
 *
 * @authors ThierrySquirrel
 * @date 2025/11/14
 **/

void MemoryCleanThread::run() {
	MemoryCleanThreadGlobal::memoryCleanThreadRun();
	bool isRun = MemoryCleanThreadGlobal::memoryCleanThreadIsRun();

	while (isRun) {
		MemoryCleanFactoryTemplate::clearedMemory();
		std::this_thread::sleep_for(std::chrono::seconds(MemoryCleanThreadGlobal::GLOBAL_MEMORY_CLEAN_THREAD_TIME));
		isRun = MemoryCleanThreadGlobal::memoryCleanThreadIsRun();
	}
}