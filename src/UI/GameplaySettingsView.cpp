#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"
#include "GlobalNamespace/GameplaySetupViewController.hpp"
#include "UI/GameplaySettingsView.hpp" 
#include "sprites.hpp"
#include "MainConfig.hpp"
#include "UnityEngine/Application.hpp"
using namespace UnityEngine;
using namespace UnityEngine::UI;
using namespace HMUI;
using namespace QuestUI::BeatSaberUI;
#include "TMPro/TextMeshProUGUI.hpp"
#include "TMPro/TextMeshPro.hpp"
#include "UnityEngine/RectOffset.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/CustomTypes/Components/Backgroundable.hpp"

using namespace PauseRemapper::UI;
using namespace TMPro;
using namespace QuestUI;

DEFINE_TYPE(PauseRemapper::UI, GameplaySettingsView);

#define SetPreferredSize(identifier, width, height)                                         \
    auto layout##identifier = identifier->get_gameObject()->GetComponent<LayoutElement*>(); \
    if (!layout##identifier)                                                                \
        layout##identifier = identifier->get_gameObject()->AddComponent<LayoutElement*>();  \
    layout##identifier->set_preferredWidth(width);                                          \
    layout##identifier->set_preferredHeight(height);                                        \
    auto fitter##identifier = identifier->GetComponent<ContentSizeFitter*>();               \
    fitter##identifier->set_verticalFit(ContentSizeFitter::FitMode::PreferredSize);         \
    fitter##identifier->set_horizontalFit(ContentSizeFitter::FitMode::PreferredSize)

void test(){
    Application::OpenURL("https://patreon.com/speecil");
}

void PauseRemapper::UI::GameplaySettingsView::DidActivate(bool firstActivation) 
{   if (!firstActivation) return;
    UnityEngine::Sprite* logo = BeatSaberUI::Base64ToSprite(Patreon);
    TMPro::TextMeshProUGUI * text;
    TMPro::TextMeshProUGUI * text1;
    TMPro::TextMeshProUGUI * text2;
    TMPro::TextMeshProUGUI * text3;
    TMPro::TextMeshProUGUI * text4;
    TMPro::TextMeshProUGUI * text5;
    TMPro::TextMeshProUGUI * text6;
    TMPro::TextMeshProUGUI * space1;
    TMPro::TextMeshProUGUI * space2;
    TMPro::TextMeshProUGUI * space3;
    TMPro::TextMeshProUGUI * space4;
    auto vertical = BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
            vertical->get_rectTransform()->set_anchoredPosition({0.0f, 0.0f});
            vertical->set_padding(RectOffset::New_ctor(2, 2, 2, 2));
            SetPreferredSize(vertical, 70.0f, 60.0f);
    text3 = QuestUI::BeatSaberUI::CreateText(vertical -> get_transform(), "Change your pause button here!");
    space1 = QuestUI::BeatSaberUI::CreateText(vertical -> get_transform(), " \n \n");
    text3 -> set_alignment(TMPro::TextAlignmentOptions::Center);
    text3 -> set_fontSize(6.0);
        
    QuestUI::BeatSaberUI::CreateDropdown(vertical, getMainConfig().Button.GetName(), getMainConfig().Button.GetValue(), { "Default", "A Button", "B Button", "X Button", "Y Button", "Left Trigger", "Right Trigger", "Left Grip", "Right Grip", "Click Left Thumbstick", "Click Right Thumbstick"},
            [](StringW value) {
                getMainConfig().Button.SetValue(value);
                getMainConfig().config->Write();
            }
        );
    space2 = QuestUI::BeatSaberUI::CreateText(vertical-> get_transform(), " ");
    QuestUI::BeatSaberUI::CreateDropdown(vertical, getMainConfig().Button2.GetName(), getMainConfig().Button2.GetValue(), { "Default", "A Button", "B Button", "X Button", "Y Button", "Left Trigger", "Right Trigger", "Left Grip", "Right Grip", "Click Left Thumbstick", "Click Right Thumbstick"},
            [](StringW value2) {
                getMainConfig().Button2.SetValue(value2);
                getMainConfig().config->Write();
            }
        );
    space3 = QuestUI::BeatSaberUI::CreateText(vertical -> get_transform(), " \n \n");
    text4 = QuestUI::BeatSaberUI::CreateText(vertical-> get_transform(), "Message speecil#5350 on discord if there are any issues");
    text4 -> set_alignment(TMPro::TextAlignmentOptions::Center);
    text4 -> set_fontStyle(TMPro::FontStyles::Normal);\
    space2 = QuestUI::BeatSaberUI::CreateText(vertical-> get_transform(), "\n \n ");
    text2 = QuestUI::BeatSaberUI::CreateText(vertical-> get_transform(), "Subscribe to my patreon for pre-release mods!");
    text2 -> set_alignment(TMPro::TextAlignmentOptions::Center);
    text2 -> set_fontStyle(TMPro::FontStyles::Normal);

    BeatSaberUI::CreateUIButton(vertical->get_transform(), "Patreon", "PlayButton", UnityEngine::Vector2(), UnityEngine::Vector2(6.0f, 11.3f), test);

    text5 = QuestUI::BeatSaberUI::CreateText(vertical -> get_transform(), "Pause Remapper v0.3.0_DEV by Speecil");
    text5 -> set_alignment(TMPro::TextAlignmentOptions::Center);
    text5 -> set_fontSize(5.0);
    text5 -> set_fontStyle(TMPro::FontStyles::Normal);
    text5 -> set_color(UnityEngine::Color::get_green());
    //AddConfigValueToggle(vertical->get_transform(), getMainConfig().EnableResume);
}

