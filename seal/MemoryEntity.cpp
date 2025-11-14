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
#include "MemoryEntity.h"

 /**
 * @file: MemoryEntity.cpp
 * @brief: C++20
 *
 * @authors ThierrySquirrel
 * @date 2025/11/14
 **/

MemoryEntity::MemoryEntity() {
	this->allMemory = -1;
	this->usedMemory = -1;
}


void MemoryEntity::setAllMemory(int& allMemory) {
	this->allMemory = allMemory;
}
int MemoryEntity::getAllMemory() {
	return this->allMemory;
}

void MemoryEntity::setUsedMemory(int& usedMemory) {
	this->usedMemory = usedMemory;
}
int MemoryEntity::getUsedMemory() {
	return this->usedMemory;
}