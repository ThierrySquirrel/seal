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

#pragma once

#include "MemoryCleanThreadExecute.h"

#include "ToastFactory.h"

#include "ControlButtonFactoryConstant.h"

#include <winrt/Windows.System.h>


 /**
 * @file: ControlButtonFactory.h
 * @brief: C++20
 *
 * @authors ThierrySquirrel
 * @date 2025/11/14
 **/
class ControlButtonFactory{
public:static void clearMemory();
public:static void stopClearMemory();

public:static void showStartStartTaskToast();
public:static void showStartTerminateTaskToast();

public:static void controlButtonStartTaskClick();
public:static void controlButtonTerminateTask();

public:static void showProjectWebsite();
public:static void showLicense();

public:static void controlButtonProjectWebsiteClick();
public:static void controlButtonLicenseClick();

};

