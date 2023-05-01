#include "main.hpp"
#include "questui/shared/QuestUI.hpp"
#include "MainConfig.hpp"
#include "GlobalNamespace/GamePause.hpp"
#include "assets.hpp"

#include "bsml/shared/BSML.hpp"
#include "UI/UIManager.hpp"
#include "bsml/shared/BSMLDataCache.hpp"
#include "main.hpp"
#include "questui/shared/QuestUI.hpp"
#include "config-utils/shared/config-utils.hpp"

#include "GlobalNamespace/OVRInput_Button.hpp"
#include "GlobalNamespace/PauseController.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"
#include "GlobalNamespace/HMMainThreadDispatcher.hpp"
#include "System/Action.hpp"
#include "UnityEngine/SceneManagement/SceneManager.hpp"
#include "UnityEngine/Time.hpp"

#include "lapiz/shared/zenject/Zenjector.hpp"
#include "Installers/PauseRemapperInstaller.hpp"

using namespace PauseRemapper::UI;
using namespace GlobalNamespace;
using namespace QuestUI;
using namespace UnityEngine;

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Returns a logger, useful for printing debug messages
Logger &getLogger()
{
    static Logger *logger = new Logger(modInfo);
    return *logger;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo &info)
{
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;

    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load()
{
    il2cpp_functions::Init();
    getMainConfig().Init(modInfo);
    custom_types::Register::AutoRegister();
    getMainConfig().Init(modInfo);
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