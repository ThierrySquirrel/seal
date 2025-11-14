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
#include "ControlTextFactoryConstant.h"

 /**
   * @file: ControlTextFactoryConstant.cpp
   * @brief: C++20
   *
   * @authors ThierrySquirrel
   * @date 2025/11/14
   **/

static const std::wstring SHOW_TOTAL_MEMORY = L"Total memory MB:";
static const std::wstring SHOW_USED_MEMORY = L"Used Memory MB:";
static const std::wstring SHOW_CLEARED_MEMORY = L"Cleared Memory MB:";
static const std::wstring SHOW_VERSION = L"Version:1.0.0";


std::wstring ControlTextFactoryConstant::showTotalMemory() {
	return SHOW_TOTAL_MEMORY;
}

std::wstring ControlTextFactoryConstant::showUsedMemory() {
	return SHOW_USED_MEMORY;
}

std::wstring ControlTextFactoryConstant::showClearedMemory() {
	return SHOW_CLEARED_MEMORY;
}

std::wstring ControlTextFactoryConstant::showVersion() {
	return SHOW_VERSION;
}