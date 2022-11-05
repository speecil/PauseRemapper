#pragma once

#include "custom-types/shared/macros.hpp"
#include "UnityEngine/MonoBehaviour.hpp"
#include "UnityEngine/UI/Dropdown.hpp"

#include "questui/shared/CustomTypes/Components/Settings/IncrementSetting.hpp"

DECLARE_CLASS_CODEGEN(PauseRemapper::UI, GameplaySettingsView, UnityEngine::MonoBehaviour,


    DECLARE_INSTANCE_FIELD(UnityEngine::UI::Dropdown*, SelectButton);
    DECLARE_INSTANCE_FIELD(UnityEngine::UI::Dropdown*, SelectButton2);

    DECLARE_INSTANCE_METHOD(void, DidActivate, bool firstActivation);

);