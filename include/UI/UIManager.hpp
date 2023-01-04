#pragma once
#include "HMUI/ViewController.hpp"

#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"
#include "bsml/shared/BSML/Components/TextGradientUpdater.hpp"
#include "bsml/shared/BSML/Tags/ButtonTag.hpp"
#include "bsml/shared/BSML/Components/Settings/ToggleSetting.hpp"
#include "bsml/shared/BSML/Tags/TextTag.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

#include "TMPro/TextMeshProUGUI.hpp"

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(PauseRemapper::UI, UIManager, Il2CppObject,
    DECLARE_INSTANCE_FIELD(HMUI::ViewController*, settingsViewController);

    BSML_OPTIONS_LIST_OBJECT(BOptions, "A Button", "B Button", "X Button", "Y Button", "Left Trigger", "Right Trigger", "Click Left Thumbstick", "Click Right Thumbstick");
    
    DECLARE_BSML_PROPERTY(StringW, Button1);
    DECLARE_BSML_PROPERTY(StringW, Button2);

    DECLARE_CTOR(ctor);
    public:
        static UIManager *get_instance();
    private:
        static SafePtr<UIManager> instance;
)