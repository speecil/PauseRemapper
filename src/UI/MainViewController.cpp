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
    space1 = QuestUI::BeatSaberUI::CreateText(container -> get_transform(), " \n \n");
    text3 = QuestUI::BeatSaberUI::CreateText(container -> get_transform(), "Pause Remapper has moved to the \n mod settings tab within song selection");
    text3 -> set_alignment(TMPro::TextAlignmentOptions::Center);
    text3 -> set_fontSize(6.0);
}

