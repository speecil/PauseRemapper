#include "main.hpp"
#include "questui/shared/QuestUI.hpp"
#include "config-utils/shared/config-utils.hpp"
#include "GlobalNamespace/OVRInput_Button.hpp"
#include "GlobalNamespace/PauseController.hpp"
#include "MainConfig.hpp"
#include "GlobalNamespace/HMMainThreadDispatcher.hpp"
#include "UI/PauseRemapperFlowCoordinator.hpp"
#include "GlobalNamespace/GamePause.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"
#include "GlobalNamespace/BeatmapObjectManager.hpp"
#include "System/Action.hpp"
using namespace GlobalNamespace;
using namespace QuestUI;
GlobalNamespace::PauseController* pauser;

ModInfo modInfo;
DEFINE_CONFIG(MainConfig);
// Loads the config from disk using our modInfo, then returns it for use
// other config tools such as config-utils don't use this config, so it can be removed if those are in use
Configuration& getConfig() {
    static Configuration config(modInfo);
    return config;
}

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

MAKE_HOOK_MATCH(AnUpdate, &HMMainThreadDispatcher::Update, void, HMMainThreadDispatcher* self) {
    AnUpdate(self);
    if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::One, OVRInput::Controller::Touch)){
        if(pauser->get_canPause()) {
                pauser->paused = true;
                pauser->gamePause->Pause();
                pauser->pauseMenuManager->ShowMenu();
                pauser->beatmapObjectManager->HideAllBeatmapObjects(true);
                pauser->beatmapObjectManager->PauseAllBeatmapObjects(true);
                if(pauser->didPauseEvent)
                    pauser->didPauseEvent->Invoke();
            }
    }
}


// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load();
    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();
    getMainConfig().Init(modInfo);
    // Initialises Quest UI
    custom_types::Register::AutoRegister();
    QuestUI::Init();
    QuestUI::Register::RegisterMainMenuModSettingsFlowCoordinator<PauseRemapper::UI::PauseRemapperFlowCoordinator*>(modInfo);

    getLogger().info("Installing hooks...");
    INSTALL_HOOK(getLogger(), AnUpdate);
    getLogger().info("Installed all hooks!");
}