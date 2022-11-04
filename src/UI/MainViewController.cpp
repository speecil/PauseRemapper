#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"

#include "UI/MainViewController.hpp" 

#include "MainConfig.hpp"

#include "TMPro/TextMeshProUGUI.hpp"
#include "TMPro/TextMeshPro.hpp"

using namespace PauseRemapper::UI;
using namespace TMPro;
using namespace QuestUI;

DEFINE_TYPE(PauseRemapper::UI, MainViewController);

void PauseRemapper::UI::MainViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) 
{   if (!firstActivation) return;
    
    TMPro::TextMeshProUGUI * text;
    TMPro::TextMeshProUGUI * text1;
    TMPro::TextMeshProUGUI * text2;
    TMPro::TextMeshProUGUI * text3;
    TMPro::TextMeshProUGUI * text4;
    TMPro::TextMeshProUGUI * text5;
    TMPro::TextMeshProUGUI * text6;
    TMPro::TextMeshProUGUI * space1;
    TMPro::TextMeshProUGUI * space2;
    UnityEngine::GameObject* container = QuestUI::BeatSaberUI::CreateScrollableSettingsContainer(get_transform());
    text3 = QuestUI::BeatSaberUI::CreateText(container -> get_transform(), "Change your pause button here");
    space1 = QuestUI::BeatSaberUI::CreateText(container -> get_transform(), "");
    text3 -> set_alignment(TMPro::TextAlignmentOptions::Center);
    text3 -> set_fontSize(6.0);
        
        QuestUI::BeatSaberUI::CreateDropdown(container, getMainConfig().Button.GetName(), getMainConfig().Button.GetValue(), { "Default", "A Button", "B Button", "X Button", "Y Button"},
            [](StringW value) {
                getMainConfig().Button.SetValue(value);
            }
        );
    //AddConfigValueToggle(container->get_transform(), getMainConfig().EnableResume);
}

