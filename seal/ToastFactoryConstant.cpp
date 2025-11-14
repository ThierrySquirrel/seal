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
#include "ToastFactoryConstant.h"

 /**
  * @file: ToastFactoryConstant.cpp
  * @brief: C++20
  *
  * @authors ThierrySquirrel
  * @date 2025/11/14
  **/

static const std::wstring PATH_SYMBOL = L"\\";

static const winrt::hstring START_TITLE = L"Start Task";
static const winrt::hstring START_CONTENT = L"Start Executing The Task";
static const winrt::hstring START_IMAGE_SRC_LOGO = L"\\Images\\Toast\\START_IMAGE_SRC_LOGO.png";
static const winrt::hstring START_IMAGE_SRC_HERO = L"\\Images\\Toast\\START_IMAGE_SRC_HERO.png";

static const winrt::hstring TERMINATE_TITLE = L"Terminate Task";
static const winrt::hstring TERMINATE_CONTENT = L"Terminate Task Execution";
static const winrt::hstring TERMINATE_IMAGE_SRC_LOGO = L"\\Images\\Toast\\TERMINATE_IMAGE_SRC_LOGO.png";
static const winrt::hstring TERMINATE_IMAGE_SRC_HERO = L"\\Images\\Toast\\TERMINATE_IMAGE_SRC_HERO.png";

winrt::hstring ToastFactoryConstant::getProjectPath() {
	wchar_t path[MAX_PATH];
	GetModuleFileName(NULL, path, MAX_PATH);

	std::wstring imageSrc(path);
	int index = imageSrc.find_last_of(PATH_SYMBOL);
	imageSrc = imageSrc.substr(0, index);

	return winrt::to_hstring(imageSrc.c_str());
}

winrt::hstring ToastFactoryConstant::getStartTitle() {
	return START_TITLE;
}
winrt::hstring ToastFactoryConstant::getStartContent() {
	return START_CONTENT;
}
winrt::hstring ToastFactoryConstant::getStartImageSrcLogo() {

	winrt::hstring imageSrc = ToastFactoryConstant::getProjectPath();
	imageSrc = imageSrc + START_IMAGE_SRC_LOGO;
	return imageSrc;

}
winrt::hstring ToastFactoryConstant::getStartImageSrcHero() {
	winrt::hstring imageSrc = ToastFactoryConstant::getProjectPath();
	imageSrc = imageSrc + START_IMAGE_SRC_HERO;
	return imageSrc;
}

winrt::hstring ToastFactoryConstant::getTerminateTitle() {
	return TERMINATE_TITLE;
}
winrt::hstring ToastFactoryConstant::getTerminateContent() {
	return TERMINATE_CONTENT;
}
winrt::hstring ToastFactoryConstant::getTerminateImageSrcLogo() {
	winrt::hstring imageSrc = ToastFactoryConstant::getProjectPath();
	imageSrc = imageSrc + TERMINATE_IMAGE_SRC_LOGO;
	return imageSrc;
}
winrt::hstring ToastFactoryConstant::getTerminateImageSrcHero() {
	winrt::hstring imageSrc = ToastFactoryConstant::getProjectPath();
	imageSrc = imageSrc + TERMINATE_IMAGE_SRC_HERO;
	return imageSrc;
}