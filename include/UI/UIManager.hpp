#pragma once
#include "HMUI/ViewController.hpp"

#include "System/Object.hpp"
#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"
#include "System/Object.hpp"
#include "bsml/shared/BSML/Tags/ButtonTag.hpp"
#include "bsml/shared/BSML/Components/Settings/ToggleSetting.hpp"
#include "bsml/shared/BSML/Tags/TextTag.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

#include "TMPro/TextMeshProUGUI.hpp"

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(PauseRemapper::UI, UIManager, System::Object,
    DECLARE_INSTANCE_FIELD(HMUI::ViewController*, settingsViewController);

    DECLARE_BSML_PROPERTY(bool, aButton);
    DECLARE_BSML_PROPERTY(bool, bButton);
    DECLARE_BSML_PROPERTY(bool, xButton);
    DECLARE_BSML_PROPERTY(bool, yButton);

    DECLARE_BSML_PROPERTY(bool, leftThumbstick);
    DECLARE_BSML_PROPERTY(bool, rightThumbstick);
    DECLARE_BSML_PROPERTY(bool, moveLThumbstick);
    DECLARE_BSML_PROPERTY(bool, moveRThumbstick);

    DECLARE_BSML_PROPERTY(bool, leftGrip);
    DECLARE_BSML_PROPERTY(bool, rightGrip);
    DECLARE_BSML_PROPERTY(bool, leftTrigger);
    DECLARE_BSML_PROPERTY(bool, rightTrigger);



    DECLARE_CTOR(ctor);
    public:
        static UIManager *get_instance();
    private:
        static SafePtr<UIManager> instance;
)