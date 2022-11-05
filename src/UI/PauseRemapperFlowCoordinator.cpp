#include "main.hpp"

#include "UI/PauseRemapperFlowCoordinator.hpp"
#include "UI/MainViewController.hpp"
#include "UI/CreditsViewController.hpp"
#include "UI/GameplaySettingsView.hpp"

#include "MainConfig.hpp"

#include "System/Action.hpp"
#include "System/Action_1.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"

#include "UI/CreditsViewController.hpp" 
#include "UI/PauseRemapperFlowCoordinator.hpp"
#include "MainConfig.hpp"

#include "UnityEngine/Object.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"

using namespace PauseRemapper::UI;
using namespace TMPro;
using namespace QuestUI;
using namespace QuestUI::BeatSaberUI;
using namespace UnityEngine;

DEFINE_TYPE(PauseRemapper::UI, PauseRemapperFlowCoordinator);

void PauseRemapper::UI::PauseRemapperFlowCoordinator::Awake() {

        MainViewController = QuestUI::BeatSaberUI::CreateViewController<PauseRemapper::UI::MainViewController*>();
        
        CreditsViewController = QuestUI::BeatSaberUI::CreateViewController<PauseRemapper::UI::CreditsViewController*>();

}


void PauseRemapper::UI::PauseRemapperFlowCoordinator::DidActivate(bool firstActivation, bool addedToHeirarchy, bool screenSystemEnabling) {
    if (firstActivation){
    SetTitle("Pause Remapper -- NOTICE", HMUI::ViewController::AnimationType::In);
    showBackButton = true;
    ProvideInitialViewControllers(MainViewController, nullptr, nullptr, CreditsViewController, nullptr);
}}

void PauseRemapper::UI::PauseRemapperFlowCoordinator::BackButtonWasPressed(HMUI::ViewController* topViewController) {
    getMainConfig().config->Write();
    this->parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
}
