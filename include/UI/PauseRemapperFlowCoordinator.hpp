#pragma once

#include "HMUI/ViewController.hpp"
#include "HMUI/FlowCoordinator.hpp"

#include "UI/MainViewController.hpp"
#include "UI/CreditsViewController.hpp"

#include "custom-types/shared/macros.hpp"

#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

DECLARE_CLASS_CODEGEN(PauseRemapper::UI, PauseRemapperFlowCoordinator, HMUI::FlowCoordinator,
                      DECLARE_INSTANCE_FIELD(PauseRemapper::UI::MainViewController*, MainViewController);
                      DECLARE_INSTANCE_FIELD(PauseRemapper::UI::CreditsViewController*, CreditsViewController);
                      //fortnite    

                      DECLARE_INSTANCE_METHOD(void, Awake);

                      DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::il2cpp_type_check::MetadataGetter<&HMUI::FlowCoordinator::DidActivate>::get(), bool firstActivation, bool addedToHeirarchy, bool screenSystemEnabling);
                      DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, il2cpp_utils::il2cpp_type_check::MetadataGetter<&HMUI::FlowCoordinator::BackButtonWasPressed>::get(), HMUI::ViewController* topViewController);
                      )