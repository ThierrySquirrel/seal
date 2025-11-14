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
#include "ControlTimeMap.h"

 /**
  * @file: ControlTimeMap.cpp
  * @brief: C++20
  *
  * @authors ThierrySquirrel
  * @date 2025/11/14
  **/

std::map<std::string, DispatcherTimer> CONTROL_TIME_MAP;
std::shared_mutex CONTROL_TIME_READ_MUTEX;
std::mutex CONTROL_TIME_WRITE_MUTEX;
const std::string CONTROL_TIME_KEY = "ControlTimeKey";

void ControlTimeMap::setMap(std::string& key, DispatcherTimer& value) {
	CONTROL_TIME_MAP[key] = value;
}
DispatcherTimer ControlTimeMap::getMap(std::string& key) {
	return CONTROL_TIME_MAP[key];
}

std::string ControlTimeMap::getControlTimeKey() {
	return CONTROL_TIME_KEY;
}
void ControlTimeMap::setControlTime() {
	std::string key = ControlTimeMap::getControlTimeKey();
	
	CONTROL_TIME_WRITE_MUTEX.lock();
	DispatcherTimer dispatcherTimer;
	ControlTimeMap::setMap(key,dispatcherTimer);
	CONTROL_TIME_WRITE_MUTEX.unlock();
}

DispatcherTimer ControlTimeMap::getControlTime() {
	std::string key = ControlTimeMap::getControlTimeKey();

	CONTROL_TIME_READ_MUTEX.lock_shared();
	std::map<std::string, DispatcherTimer>::iterator mapIterator = CONTROL_TIME_MAP.find(key);
	if (mapIterator == CONTROL_TIME_MAP.end()) {
		ControlTimeMap::setControlTime();
	}
	DispatcherTimer value = ControlTimeMap::getMap(key);
	CONTROL_TIME_READ_MUTEX.unlock_shared();

	return value;
}