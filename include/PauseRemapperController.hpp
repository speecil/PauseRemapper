#pragma once

#include "GlobalNamespace/AudioTimeSyncController.hpp"
#include "GlobalNamespace/IReadonlyBeatmapData.hpp"
#include "GlobalNamespace/VRController.hpp"
#include "GlobalNamespace/IDifficultyBeatmap.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"
#include "System/IDisposable.hpp"
#include "Zenject/DiContainer.hpp"
#include "Zenject/IInitializable.hpp"
#include "custom-types/shared/macros.hpp"
#include "lapiz/shared/macros.hpp"
#include "UnityEngine/MonoBehaviour.hpp"
#include "GlobalNamespace/ComboUIController.hpp"
#include "GlobalNamespace/ComboController.hpp"
#include "TMPro/TextMeshProUGUI.hpp"
#include "GlobalNamespace/PauseController.hpp"
#include <vector>
#include "Zenject/ITickable.hpp"

using namespace GlobalNamespace;

#define INTERFACES                                                        \
    {                                                                     \
        classof(System::IDisposable*), classof(Zenject::IInitializable*), classof(Zenject::ITickable*)\
    }

___DECLARE_TYPE_WRAPPER_INHERITANCE(PauseRemapper, PauseRemapperController, Il2CppTypeEnum::IL2CPP_TYPE_CLASS, Il2CppObject, "PauseRemapper", INTERFACES, 0, nullptr,
                                    DECLARE_PRIVATE_FIELD(PauseController*, _pauseController);
                                    DECLARE_PRIVATE_FIELD(PauseMenuManager*, _pauseMenuManager);
                                    DECLARE_CTOR(ctor, PauseController* pauseController, PauseMenuManager* pauseMenuManager);
                                    DECLARE_OVERRIDE_METHOD(void, Initialize, il2cpp_utils::il2cpp_type_check::MetadataGetter<&::Zenject::IInitializable::Initialize>::get());
                                    DECLARE_OVERRIDE_METHOD(void, Dispose, il2cpp_utils::il2cpp_type_check::MetadataGetter<&::System::IDisposable::Dispose>::get());
                                    DECLARE_OVERRIDE_METHOD(void, Tick, il2cpp_utils::il2cpp_type_check::MetadataGetter<&::Zenject::ITickable::Tick>::get());
                                    private:
                                        float timeHeld;
                                        bool buttonPressed;
                                        void PauseTrigger();
                                        void OnPause();
                                    )

#undef INTERFACES