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

#include <winrt/Windows.Data.Xml.Dom.h>

#include <winrt/Windows.UI.Notifications.h>

#include "ToastFactoryConstant.h"

using namespace winrt::Windows::Data::Xml::Dom;

 /**
  * @file: ToastFactory.h
  * @brief: C++20
  *
  * @authors ThierrySquirrel
  * @date 2025/11/14
  **/
class ToastFactory{
private:static winrt::Windows::UI::Notifications::ToastNotification createToast(winrt::hstring title, winrt::hstring content, winrt::hstring imageSrcLogo, winrt::hstring imageSrcHero);

public:static void startTask();

public:static void terminateTask();
};

