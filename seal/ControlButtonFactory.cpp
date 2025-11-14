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
#include "ControlButtonFactory.h"

 /**
 * @file: ControlButtonFactory.cpp
 * @brief: C++20
 *
 * @authors ThierrySquirrel
 * @date 2025/11/14
 **/

void ControlButtonFactory::clearMemory() {
	MemoryCleanThreadExecute::executeMemoryClean();
}

void ControlButtonFactory::stopClearMemory(){
	MemoryCleanThreadExecute::stopMemoryClean();
}

void ControlButtonFactory::showStartStartTaskToast() {
	ToastFactory::startTask();
}
void ControlButtonFactory::showStartTerminateTaskToast() {
	ToastFactory::terminateTask();
}

void ControlButtonFactory::controlButtonStartTaskClick() {
	ControlButtonFactory::showStartStartTaskToast();
	ControlButtonFactory::clearMemory();
}

void ControlButtonFactory::controlButtonTerminateTask() {
	ControlButtonFactory::showStartTerminateTaskToast();
	ControlButtonFactory::stopClearMemory();
}

void ControlButtonFactory::showProjectWebsite() {

	winrt::Windows::Foundation::Uri uri(ControlButtonFactoryConstant::getProjectWebsite());

	winrt::Windows::System::Launcher::LaunchUriAsync(uri);
}
void ControlButtonFactory::showLicense() {

	winrt::Windows::Foundation::Uri uri(ControlButtonFactoryConstant::getLicense());
	winrt::Windows::System::Launcher::LaunchUriAsync(uri);
}

void ControlButtonFactory::controlButtonProjectWebsiteClick() {
	ControlButtonFactory::showProjectWebsite();
}
void ControlButtonFactory::controlButtonLicenseClick() {
	ControlButtonFactory::showLicense();
}