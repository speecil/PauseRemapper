#include "main.hpp"

#include "assets.hpp"

#include "bsml/shared/BSML.hpp"
#include "UI/UIManager.hpp"
#include "bsml/shared/BSMLDataCache.hpp"


#include "lapiz/shared/zenject/Zenjector.hpp"
#include "Installers/PauseRemapperInstaller.hpp"

#include "Logging.hpp"

using namespace PauseRemapper::UI;
using namespace GlobalNamespace;
using namespace UnityEngine;

static modloader::ModInfo modInfo{MOD_ID, VERSION, 0};

PAUSE_REMAPPER_EXPORT_FUNC void setup(CModInfo* info)
{
    *info = modInfo.to_c();
    INFO("Completed setup!");
}

PAUSE_REMAPPER_EXPORT_FUNC void late_load()
{
    il2cpp_functions::Init();
    custom_types::Register::AutoRegister();

    BSML::Init();
    BSML::Register::RegisterGameplaySetupTab("Pause Remapper", MOD_ID "_settings", UIManager::get_instance(), BSML::MenuType::All);

    auto zenjector = Lapiz::Zenject::Zenjector::Get();
    zenjector->Install<PauseRemapper::Installers::PauseRemapperInstaller*, GlobalNamespace::StandardGameplayInstaller*>();
}

BSML_DATACACHE(settings)
{
    return IncludedAssets::settings_bsml;
}