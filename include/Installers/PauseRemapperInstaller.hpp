#pragma once

#include "UnityEngine/GameObject.hpp"
#include "Zenject/InjectContext.hpp"
#include "Zenject/Installer.hpp"
#include "custom-types/shared/macros.hpp"
#include "lapiz/shared/macros.hpp"
#include "PauseRemapperController.hpp"

DECLARE_CLASS_CODEGEN(PauseRemapper::Installers, PauseRemapperInstaller, ::Zenject::Installer,
                      DECLARE_OVERRIDE_METHOD(void, InstallBindings, il2cpp_utils::il2cpp_type_check::MetadataGetter<&::Zenject::Installer::InstallBindings>::methodInfo());
                      DECLARE_DEFAULT_CTOR();
                      DECLARE_INSTANCE_FIELD_PRIVATE(PauseRemapper::PauseRemapperController*, _controllerPrefab);
                      )