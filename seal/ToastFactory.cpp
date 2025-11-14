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
#include "ToastFactory.h"

 /**
  * @file: ToastFactory.cpp
  * @brief: C++20
  *
  * @authors ThierrySquirrel
  * @date 2025/11/14
  **/


static const winrt::hstring TOAST = L"toast";
static const winrt::hstring VISUAL = L"visual";
static const winrt::hstring BINDING = L"binding";

static const winrt::hstring BINDING_KEY_TEMPLATE = L"template";
static const winrt::hstring BINDING_VALUE_TOAST_GENERIC = L"ToastGeneric";

static const winrt::hstring TEXT = L"text";
static const winrt::hstring IMAGE = L"image";

static const winrt::hstring IMAGE_KEY_PLACEMENT = L"placement";
static const winrt::hstring IMAGE_VALUE_APPLOGOOVERRIDE = L"appLogoOverride";
static const winrt::hstring IMAGE_VALUE_HERO = L"hero";


static const winrt::hstring IMAGE_KEY_SRC = L"src";
static const winrt::hstring IMAGE_KEY_HINT_CROP = L"hint-crop";
static const winrt::hstring IMAGE_VALUE_CIRCLE = L"circle";


winrt::Windows::UI::Notifications::ToastNotification ToastFactory::createToast(winrt::hstring title, winrt::hstring content, winrt::hstring imageSrcLogo, winrt::hstring imageSrcHero) {

    XmlDocument xmlDocument;
    XmlElement toast = xmlDocument.CreateElement(TOAST);
    xmlDocument.AppendChild(toast);

    XmlElement visual = xmlDocument.CreateElement(VISUAL);
    toast.AppendChild(visual);

    XmlElement bindinga = xmlDocument.CreateElement(BINDING);
    bindinga.SetAttribute(BINDING_KEY_TEMPLATE, BINDING_VALUE_TOAST_GENERIC);
    visual.AppendChild(bindinga);

    winrt::Windows::Data::Xml::Dom::XmlElement textTitle = xmlDocument.CreateElement(TEXT);
    textTitle.InnerText(title);
    bindinga.AppendChild(textTitle);

    winrt::Windows::Data::Xml::Dom::XmlElement textContent = xmlDocument.CreateElement(TEXT);
    textContent.InnerText(content);
    bindinga.AppendChild(textContent);

    winrt::Windows::Data::Xml::Dom::XmlElement imageLogo = xmlDocument.CreateElement(IMAGE);
    imageLogo.SetAttribute(IMAGE_KEY_PLACEMENT, IMAGE_VALUE_APPLOGOOVERRIDE);
    imageLogo.SetAttribute(IMAGE_KEY_SRC, imageSrcLogo);
    imageLogo.SetAttribute(IMAGE_KEY_HINT_CROP, IMAGE_VALUE_CIRCLE);
    bindinga.AppendChild(imageLogo);

    winrt::Windows::Data::Xml::Dom::XmlElement imageHero = xmlDocument.CreateElement(L"image");
    imageHero.SetAttribute(IMAGE_KEY_PLACEMENT, IMAGE_VALUE_HERO);
    imageHero.SetAttribute(IMAGE_KEY_SRC, imageSrcHero);
    imageLogo.SetAttribute(IMAGE_KEY_HINT_CROP, IMAGE_VALUE_CIRCLE);
    bindinga.AppendChild(imageHero);

    return winrt::Windows::UI::Notifications::ToastNotification(xmlDocument);
}

void ToastFactory::startTask() {
    winrt::Windows::UI::Notifications::ToastNotification totast = ToastFactory::createToast(ToastFactoryConstant::getStartTitle(),
        ToastFactoryConstant::getStartContent(),
        ToastFactoryConstant::getStartImageSrcLogo(),
        ToastFactoryConstant::getStartImageSrcHero());

    winrt::Windows::UI::Notifications::ToastNotificationManager::CreateToastNotifier().Show(totast);
}

void ToastFactory::terminateTask() {
    winrt::Windows::UI::Notifications::ToastNotification totast = ToastFactory::createToast(ToastFactoryConstant::getTerminateTitle(),
        ToastFactoryConstant::getTerminateContent(),
        ToastFactoryConstant::getTerminateImageSrcLogo(),
        ToastFactoryConstant::getTerminateImageSrcHero());

    winrt::Windows::UI::Notifications::ToastNotificationManager::CreateToastNotifier().Show(totast);
}
