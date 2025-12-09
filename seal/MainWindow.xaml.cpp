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
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

/**
   * @file: MainWindow.xaml.cpp
   * @brief: C++20
   *
   * @authors ThierrySquirrel
   * @date 2025/11/14
   **/
namespace winrt::seal::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }


    void winrt::seal::implementation::MainWindow::controlButtonStartTaskClick(Windows::Foundation::IInspectable const& sender,
        Microsoft::UI::Xaml::RoutedEventArgs const& args) {

        controlButtonStartTask().IsEnabled(false);
        controlButtonTerminateTask().IsEnabled(true);

        ControlButtonFactory::controlButtonStartTaskClick();
    }

    void winrt::seal::implementation::MainWindow::controlButtonTerminateTaskClick(Windows::Foundation::IInspectable const& sender,
        Microsoft::UI::Xaml::RoutedEventArgs const& args) {

        controlButtonStartTask().IsEnabled(true);
        controlButtonTerminateTask().IsEnabled(false);
        
        ControlButtonFactory::controlButtonTerminateTask();
    }

    void winrt::seal::implementation::MainWindow::controlButtonGpuAccelerationClick(Windows::Foundation::IInspectable const& sender,
        Microsoft::UI::Xaml::RoutedEventArgs const& args) {
        controlButtonPauseGpu().IsEnabled(true);
        controlButtonGpuAcceleration().IsEnabled(false);
        controlMedia().MediaPlayer().Play();
    }
    void winrt::seal::implementation::MainWindow::controlButtonPauseGpuClick(Windows::Foundation::IInspectable const& sender,
        Microsoft::UI::Xaml::RoutedEventArgs const& args) {
        controlButtonPauseGpu().IsEnabled(false);
		controlButtonGpuAcceleration().IsEnabled(true);
		controlMedia().MediaPlayer().Pause();
    }

    void winrt::seal::implementation::MainWindow::controlButtonProjectWebsiteClick(Windows::Foundation::IInspectable const& sender,
        Microsoft::UI::Xaml::RoutedEventArgs const& args) {

        ControlButtonFactory::controlButtonProjectWebsiteClick();
    }

    void winrt::seal::implementation::MainWindow::controlButtonLicenseClick(Windows::Foundation::IInspectable const& sender,
        Microsoft::UI::Xaml::RoutedEventArgs const& args) {

        ControlButtonFactory::controlButtonLicenseClick();
    }

    void winrt::seal::implementation::MainWindow::updateTotalMemory() {
        std::wstring totalMemory = ControlTextFactory::getTotalMemory();
        controlTextTotalMemory().Text(totalMemory);
    }
    void winrt::seal::implementation::MainWindow::updateUsedMemory() {
        std::wstring userMemory = ControlTextFactory::getUserMemory();
        controlTextUsedMemory().Text(userMemory);
    }

    void winrt::seal::implementation::MainWindow::updateClearedMemory() {
        std::wstring clearedMemory = ControlTextFactory::getClearedMemory();
        controlTextClearedMemory().Text(clearedMemory);

    }

    void winrt::seal::implementation::MainWindow::updateVersion() {
        std::wstring version = ControlTextFactory::getVersion();
        controlTextlVersion().Text(version);
    }

    void winrt::seal::implementation::MainWindow::updateAllUi() {
        winrt::seal::implementation::MainWindow::updateTotalMemory();
        winrt::seal::implementation::MainWindow::updateUsedMemory();
        winrt::seal::implementation::MainWindow::updateClearedMemory();
        winrt::seal::implementation::MainWindow::updateVersion();

    }

    void winrt::seal::implementation::MainWindow::initializeControlIcon() {
        winrt::hstring iconPath = IconFactory::getIconPath();
        winrt::seal::implementation::MainWindow::AppWindow().SetIcon(iconPath);
    }

    void winrt::seal::implementation::MainWindow::initializeControlMedia() {
        controlMedia().MediaPlayer().IsLoopingEnabled(true);
        controlMedia().MediaPlayer().IsMuted(true);
        controlButtonPauseGpu().IsEnabled(true);
        controlButtonGpuAcceleration().IsEnabled(false);
    }

    void winrt::seal::implementation::MainWindow::initializeControlTime() {
        DispatcherTimer dispatcherTimer = ControlTimeContainer::getControlTime();
        bool isEnabled = dispatcherTimer.IsEnabled();
        if (!isEnabled) {
            int updateAllUiTime = ControlTimeConstant::getUpdateAllUiTime();
            dispatcherTimer.Interval(winrt::Windows::Foundation::TimeSpan(updateAllUiTime));
            dispatcherTimer.Tick(std::bind(&winrt::seal::implementation::MainWindow::updateAllUi, this));
            dispatcherTimer.Start();
        }
    }

    void winrt::seal::implementation::MainWindow::initializeControlAll() {
        winrt::seal::implementation::MainWindow::initializeControlIcon();
        winrt::seal::implementation::MainWindow::initializeControlMedia();
        winrt::seal::implementation::MainWindow::initializeControlTime();
    }

}