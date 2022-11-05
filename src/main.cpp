#include "main.hpp"
#include "questui/shared/QuestUI.hpp"
#include "MainConfig.hpp"

#include "extern/includes/bs-utils/shared/utils.hpp"
#include "config-utils/shared/config-utils.hpp"
#include "GlobalNamespace/OVRInput_Button.hpp"
#include "GlobalNamespace/PauseController.hpp"
#include "GlobalNamespace/PauseAnimationController.hpp"
#include "UI/GameplaySettingsView.hpp"
#include "GlobalNamespace/HMMainThreadDispatcher.hpp"
#include "UI/PauseRemapperFlowCoordinator.hpp"
#include "GlobalNamespace/GamePause.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"
#include "GlobalNamespace/BeatmapObjectManager.hpp"
#include "System/Action.hpp"
#include "UnityEngine/SceneManagement/SceneManager.hpp"

using namespace GlobalNamespace;
using namespace QuestUI;
PauseController* pauser;
int shouldpause;
bool inGameplay;
bool paused;


static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

DEFINE_CONFIG(MainConfig);

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

MAKE_HOOK_MATCH(SceneChanged, &UnityEngine::SceneManagement::SceneManager::Internal_ActiveSceneChanged, void, UnityEngine::SceneManagement::Scene prevScene, UnityEngine::SceneManagement::Scene nextScene) {
    SceneChanged(prevScene, nextScene);
    if(nextScene && nextScene.get_name() == "GameCore") {
        inGameplay = true;
        paused = false;
        pauser = UnityEngine::Resources::FindObjectsOfTypeAll<PauseController*>().FirstOrDefault();
    } else inGameplay = false;
}

MAKE_HOOK_MATCH(AnUpdate, &HMMainThreadDispatcher::Update, void, HMMainThreadDispatcher* self) {
    AnUpdate(self);
    // A button
    if(getMainConfig().Button.GetValue() == "A Button"){
        
        if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::One, OVRInput::Controller::Touch)){
            shouldpause = 1;
        }
        else{
            shouldpause = 0;
        }
        if(!inGameplay)
            return;
            switch (shouldpause) {
            case 0:
                break;
            case 1:
                getLogger().info("paused");
                if(pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                    pauser->Pause();
                }
                break;
            default:
                break;
            }
    }
    if(getMainConfig().Button2.GetValue() == "A Button"){
        
        if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::One, OVRInput::Controller::Touch)){
            shouldpause = 1;
        }
        else{
            shouldpause = 0;
        }
        if(!inGameplay)
            return;
            switch (shouldpause) {
            case 0:
                break;
            case 1:
                getLogger().info("paused");
                if(pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                    pauser->Pause();
                }
                break;
            default:
                break;
            }
    }
    // B button
    if(getMainConfig().Button.GetValue() == "B Button"){
        
        if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Two, OVRInput::Controller::Touch)){
            shouldpause = 1;
        }
        else{
            shouldpause = 0;
        }
        if(!inGameplay)
            return;
            switch (shouldpause) {
            case 0:
                break;
            case 1:
                getLogger().info("paused");
                if(pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                    pauser->Pause();
                }
                break;
            default:
                break;
            }
    }
    if(getMainConfig().Button2.GetValue() == "B Button"){
        
        if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Two, OVRInput::Controller::Touch)){
            shouldpause = 1;
        }
        else{
            shouldpause = 0;
        }
        if(!inGameplay)
            return;
            switch (shouldpause) {
            case 0:
                break;
            case 1:
                getLogger().info("paused");
                if(pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                    pauser->Pause();
                }
                break;
            default:
                break;
            }
    }
    // X Button
    if(getMainConfig().Button.GetValue() == "X Button"){
        
        if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Three, OVRInput::Controller::Touch)){
            shouldpause = 1;
        }
        else{
            shouldpause = 0;
        }
        if(!inGameplay)
            return;
            switch (shouldpause) {
            case 0:
                break;
            case 1:
                getLogger().info("paused");
                if(pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                    pauser->Pause();
                }
                break;
            default:
                break;
            }
    }
    if(getMainConfig().Button2.GetValue() == "X Button"){
        
        if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Three, OVRInput::Controller::Touch)){
            shouldpause = 1;
        }
        else{
            shouldpause = 0;
        }
        if(!inGameplay)
            return;
            switch (shouldpause) {
            case 0:
                break;
            case 1:
                getLogger().info("paused");
                if(pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                    pauser->Pause();
                }
                break;
            default:
                break;
            }
    }
    // Y Button
    if(getMainConfig().Button.GetValue() == "Y Button"){
        if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Four, OVRInput::Controller::Touch)){
            shouldpause = 1;
        }
        else{
            shouldpause = 0;
        }
        if(!inGameplay)
            return;
            switch (shouldpause) {
            case 0:
                break;
            case 1:
                getLogger().info("paused");
                if(pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                    pauser->Pause();
                }
                break;
            default:
                break;
            }
    }
    if(getMainConfig().Button2.GetValue() == "Y Button"){
        if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Four, OVRInput::Controller::Touch)){
            shouldpause = 1;
        }
        else{
            shouldpause = 0;
        }
        if(!inGameplay)
            return;
            switch (shouldpause) {
            case 0:
                break;
            case 1:
                getLogger().info("paused");
                if(pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                    pauser->Pause();
                }
                break;
            default:
                break;
            }
    }
    // Left Trigger
    if(getMainConfig().Button.GetValue() == "Left Trigger"){
        if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryIndexTrigger, OVRInput::Controller::Touch)){
            shouldpause = 1;
        }
        else{
            shouldpause = 0;
        }
        if(!inGameplay)
            return;
            switch (shouldpause) {
            case 0:
                break;
            case 1:
                getLogger().info("paused");
                if(pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                    pauser->Pause();
                }
                break;
            default:
                break;
            }
    }
    if(getMainConfig().Button2.GetValue() == "Left Trigger"){
        if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryIndexTrigger, OVRInput::Controller::Touch)){
            shouldpause = 1;
        }
        else{
            shouldpause = 0;
        }
        if(!inGameplay)
            return;
            switch (shouldpause) {
            case 0:
                break;
            case 1:
                getLogger().info("paused");
                if(pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                    pauser->Pause();
                }
                break;
            default:
                break;
            }
    }
    // Right Trigger
    if(getMainConfig().Button.GetValue() == "Right Trigger"){
        if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryIndexTrigger, OVRInput::Controller::Touch)){
            shouldpause = 1;
        }
        else{
            shouldpause = 0;
        }
        if(!inGameplay)
            return;
            switch (shouldpause) {
            case 0:
                break;
            case 1:
                getLogger().info("paused");
                if(pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                    pauser->Pause();
                }
                break;
            default:
                break;
            }
    }
    if(getMainConfig().Button2.GetValue() == "Right Trigger"){
        if(GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryIndexTrigger, OVRInput::Controller::Touch)){
            shouldpause = 1;
        }
        else{
            shouldpause = 0;
        }
        if(!inGameplay)
            return;
            switch (shouldpause) {
            case 0:
                break;
            case 1:
                getLogger().info("paused");
                if(pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                    pauser->Pause();
                }
                break;
            default:
                break;
            }
    }
}


MAKE_HOOK_MATCH(Pause, &PauseController::Pause, void, PauseController* self) {
    Pause(self);
    paused = true;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;

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
    QuestUI::Register::RegisterGameplaySetupMenu<PauseRemapper::UI::GameplaySettingsView*>(modInfo, "Pause Remapper");
    getLogger().info("Installing hooks...");
    INSTALL_HOOK(getLogger(), AnUpdate);
    INSTALL_HOOK(getLogger(), SceneChanged);
    INSTALL_HOOK(getLogger(), Pause);
    getLogger().info("Installed all hooks!");
}