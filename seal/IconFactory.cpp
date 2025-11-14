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
#include "IconFactory.h"

 /**
  * @file: IconFactory.cpp
  * @brief: C++20
  *
  * @authors ThierrySquirrel
  * @date 2025/11/14
  **/

static const std::wstring PATH_SYMBOL = L"\\";
static const winrt::hstring ICON_PATH = L"\\Images\\Icon\\favicon.ico";
winrt::hstring IconFactory::getProjectPath() {
	wchar_t path[MAX_PATH];
	GetModuleFileName(NULL, path, MAX_PATH);

	std::wstring imageSrc(path);
	int index = imageSrc.find_last_of(PATH_SYMBOL);
	imageSrc = imageSrc.substr(0, index);

	return winrt::to_hstring(imageSrc.c_str());
}
winrt::hstring IconFactory::getIconPath() {
	winrt::hstring iconPath = IconFactory::getProjectPath();
	iconPath = iconPath + ICON_PATH;
	return iconPath;
}