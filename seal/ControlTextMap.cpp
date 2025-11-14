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
#include "ControlTextMap.h"

 /**
  * @file: ControlTextMap.cpp
  * @brief: C++20
  *
  * @authors ThierrySquirrel
  * @date 2025/11/14
  **/

std::map<std::wstring, int> CONTROL_TEXT_MAP;
const std::wstring CLEARED_MEMORY_KEY = L"ClearedMemoryKey";
const std::wstring CLEARED_MEMORY_MUTEX_KEY = L"ClearedMemoryMutexKey";
const int MAX_CLEARED_MEMORY_MB = 1073741824;

ControlTextMap::ControlTextMap() {
	ControlTextMap::MUTEX_MAP[CLEARED_MEMORY_MUTEX_KEY];
}

void ControlTextMap::setMap(std::wstring& key, int& value) {
	CONTROL_TEXT_MAP[key] = value;
}
int ControlTextMap::getMap(std::wstring& key) {

	std::map<std::wstring, int>::iterator mapIterator = CONTROL_TEXT_MAP.find(key);
	if (mapIterator == CONTROL_TEXT_MAP.end()) {
		return -1;
	}
	return CONTROL_TEXT_MAP[key];
}

std::wstring ControlTextMap::getClearedMemoryKey() {
	return CLEARED_MEMORY_KEY;
}
std::wstring ControlTextMap::getClearedMemoryMutexKey() {
	return CLEARED_MEMORY_MUTEX_KEY;
}

void ControlTextMap::setClearedMemory(int& value) {
	std::wstring mutexKey = ControlTextMap::getClearedMemoryMutexKey();
	ControlTextMap::MUTEX_MAP[mutexKey].lock();

	if (value > MAX_CLEARED_MEMORY_MB) {
		value = 0;
	}
	std::wstring key = ControlTextMap::getClearedMemoryKey();
	ControlTextMap::setMap(key, value);

	ControlTextMap::MUTEX_MAP[mutexKey].unlock();
}
int ControlTextMap::getClearedMemory() {
	std::wstring mutexKey = ControlTextMap::getClearedMemoryMutexKey();
	ControlTextMap::MUTEX_MAP[mutexKey].lock_shared();
	
	std::wstring key = ControlTextMap::getClearedMemoryKey();
	int value = ControlTextMap::getMap(key);

	ControlTextMap::MUTEX_MAP[mutexKey].unlock_shared();

	return value;
}