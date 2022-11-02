#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"

#include "UI/CreditsViewController.hpp" 
#include "UI/PauseRemapperFlowCoordinator.hpp"
#include "MainConfig.hpp"

#include "UnityEngine/Object.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"
using namespace UnityEngine::UI;
using namespace UnityEngine;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "TMPro/TextMeshProUGUI.hpp"
#include "TMPro/TextAlignmentOptions.hpp"
using namespace TMPro;

DEFINE_TYPE(PauseRemapper::UI, CreditsViewController);

    TMPro::TextMeshProUGUI * text;
    TMPro::TextMeshProUGUI * text1;
    TMPro::TextMeshProUGUI * text2;
    TMPro::TextMeshProUGUI * text3;
    TMPro::TextMeshProUGUI * text4;
    TMPro::TextMeshProUGUI * text5;
    TMPro::TextMeshProUGUI * text6;
    TMPro::TextMeshProUGUI * space1;
    TMPro::TextMeshProUGUI * space2;
void PauseRemapper::UI::CreditsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) 
{   if (!firstActivation) return;
    UnityEngine::UI::VerticalLayoutGroup* layout = QuestUI::BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
    space1 = QuestUI::BeatSaberUI::CreateText(layout -> get_transform(), "");
    space2 = QuestUI::BeatSaberUI::CreateText(layout -> get_transform(), "");
    text4 = QuestUI::BeatSaberUI::CreateText(layout-> get_transform(), "Message speecil#5350 on discord if there are any issues");
    text4 -> set_alignment(TMPro::TextAlignmentOptions::Center);
    text4 -> set_fontStyle(TMPro::FontStyles::Normal);
    text5 = QuestUI::BeatSaberUI::CreateText(layout -> get_transform(), "Pause Remapper 0.1.0");
    text5 -> set_alignment(TMPro::TextAlignmentOptions::Center);
    text5 -> set_fontSize(5.0);
    text5 -> set_fontStyle(TMPro::FontStyles::Normal);
    text5 -> set_color(UnityEngine::Color::get_green());
  }
