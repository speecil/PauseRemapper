#include "main.hpp"

#include "assets.hpp"

#include "bsml/shared/BSML.hpp"
#include "UI/UIManager.hpp"
#include "bsml/shared/BSMLDataCache.hpp"


#include "lapiz/shared/zenject/Zenjector.hpp"
#include "Installers/PauseRemapperInstaller.hpp"

using namespace PauseRemapper::UI;
using namespace GlobalNamespace;
using namespace UnityEngine;

static CModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Called at the early stages of game loading
PAUSE_REMAPPER_EXPORT_FUNC void setup(CModInfo &info)
{
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;
}

// Called later on in the game loading - a good time to install function hooks
PAUSE_REMAPPER_EXPORT_FUNC void late_load()
{
    il2cpp_functions::Init();
    custom_types::Register::AutoRegister();
    // Initialises BSML**** and a gameplay settings menu
    BSML::Init();
    BSML::Register::RegisterGameplaySetupTab("Pause Remapper", MOD_ID "_settings", UIManager::get_instance(), BSML::MenuType::All);
    auto zenjector = Lapiz::Zenject::Zenjector::Get();
    zenjector->Install<PauseRemapper::Installers::PauseRemapperInstaller*, GlobalNamespace::StandardGameplayInstaller*>();
}

BSML_DATACACHE(settings)
{
    return IncludedAssets::settings_bsml;
}