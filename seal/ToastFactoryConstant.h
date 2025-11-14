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

 /**
  * @file: ToastFactoryConstant.h
  * @brief: C++20
  *
  * @authors ThierrySquirrel
  * @date 2025/11/14
  **/
class ToastFactoryConstant{
private:static winrt::hstring getProjectPath();
public:static winrt::hstring getStartTitle();
public:static winrt::hstring getStartContent();
public:static winrt::hstring getStartImageSrcLogo();
public:static winrt::hstring getStartImageSrcHero();

public:static winrt::hstring getTerminateTitle();
public:static winrt::hstring getTerminateContent();
public:static winrt::hstring getTerminateImageSrcLogo();
public:static winrt::hstring getTerminateImageSrcHero();
};

