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

#include "MainWindow.g.h"


#include "ControlTextFactory.h"

#include "ControlTimeContainer.h"
#include "ControlTimeConstant.h"

#include "ControlButtonFactory.h"

#include "IconFactory.h"
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Windowing.h>

#include<winrt/Windows.Media.Playback.h>

#include <functional> 

 /**
   * @file: MainWindow.xaml.h
   * @brief: C++20
   *
   * @authors ThierrySquirrel
   * @date 2025/11/14
   **/
namespace winrt::seal::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow(){
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void InitializeComponent() {
            MainWindowT::InitializeComponent();
            initializeControlAll();
        }

        void controlButtonStartTaskClick(Windows::Foundation::IInspectable const& sender,
            Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void controlButtonTerminateTaskClick(Windows::Foundation::IInspectable const& sender,
            Microsoft::UI::Xaml::RoutedEventArgs const& args);

        void controlButtonProjectWebsiteClick(Windows::Foundation::IInspectable const& sender,
            Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void controlButtonLicenseClick(Windows::Foundation::IInspectable const& sender,
            Microsoft::UI::Xaml::RoutedEventArgs const& args);

        void updateTotalMemory();
        void updateUsedMemory();
        void updateClearedMemory();
        void updateVersion();
        void updateAllUi();

        void initializeControlIcon();
        void initializeControlMedia();
        void initializeControlTime();
        void initializeControlAll();
    };
}

namespace winrt::seal::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>{
    };
}
