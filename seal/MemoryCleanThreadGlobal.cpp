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
#include "MemoryCleanThreadGlobal.h"

 /**
 * @file: MemoryCleanThreadGlobal.cpp
 * @brief: C++20
 *
 * @authors ThierrySquirrel
 * @date 2025/11/14
 **/

static std::shared_mutex MEMORY_CLEAN_THREAD_MUTEX;
static bool GLOBAL_MEMORY_CLEAN_THREAD_IS_RUN;
void MemoryCleanThreadGlobal::memoryCleanThreadRun() {
	MEMORY_CLEAN_THREAD_MUTEX.lock();
	GLOBAL_MEMORY_CLEAN_THREAD_IS_RUN = true;
	MEMORY_CLEAN_THREAD_MUTEX.unlock();
}
void MemoryCleanThreadGlobal::memoryCleanThreadStop() {
	MEMORY_CLEAN_THREAD_MUTEX.lock();
	GLOBAL_MEMORY_CLEAN_THREAD_IS_RUN = false;
	MEMORY_CLEAN_THREAD_MUTEX.unlock();
}

bool MemoryCleanThreadGlobal::memoryCleanThreadIsRun() {
	bool isRun;
	MEMORY_CLEAN_THREAD_MUTEX.lock_shared();
	isRun = GLOBAL_MEMORY_CLEAN_THREAD_IS_RUN;
	MEMORY_CLEAN_THREAD_MUTEX.unlock_shared();
	return isRun;
}