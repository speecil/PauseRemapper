#include "main.hpp"
#include "questui/shared/QuestUI.hpp"
#include "MainConfig.hpp"

#include "extern/includes/bs-utils/shared/utils.hpp"
#include "config-utils/shared/config-utils.hpp"
#include "GlobalNamespace/OVRInput_Button.hpp"
#include "GlobalNamespace/PauseController.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"
#include "UI/GameplaySettingsView.hpp"
#include "GlobalNamespace/HMMainThreadDispatcher.hpp"
#include "UI/PauseRemapperFlowCoordinator.hpp"
#include "System/Action.hpp"
#include "UnityEngine/SceneManagement/SceneManager.hpp"
#include "UnityEngine/Time.hpp"

#include "System/Collections/IEnumerator.hpp"
#include "system/Collections/IDictionaryEnumerator.hpp"
#include "GlobalNamespace/GamePause.hpp"
#include "custom-types/shared/coroutine.hpp"
using namespace GlobalNamespace;
using namespace QuestUI;
PauseController* pauser;
PauseMenuManager* pauseMENU;
bool test = true;
int shouldpause;
bool inGameplay;
bool paused;
bool alreadyPressed;
int wait;

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

DEFINE_CONFIG(MainConfig); // Declares the config

// Returns a logger, useful for printing debug messages
Logger& getLogger()
{
    static Logger* logger = new Logger(modInfo);
    return *logger;
}


// Hook for seeing what scene the game is currently in
MAKE_HOOK_MATCH(SceneChanged, &UnityEngine::SceneManagement::SceneManager::Internal_ActiveSceneChanged, void, UnityEngine::SceneManagement::Scene prevScene, UnityEngine::SceneManagement::Scene nextScene)
{
    SceneChanged(prevScene, nextScene);
    // Check that the scene is primary gameplay
    if (nextScene && nextScene.get_name() == "GameCore") {
        // if in primary gameplay, then set the bools accordingly
        inGameplay = true;
        paused = false;
        // Find both unity objects of *PauseController* and *PauseMenuManager* and assign them to pauser, pauseMENU
        pauser = UnityEngine::Resources::FindObjectsOfTypeAll<PauseController*>().FirstOrDefault();
        pauseMENU = UnityEngine::Resources::FindObjectsOfTypeAll<PauseMenuManager*>().FirstOrDefault();
    }
    else
        inGameplay = false;
}

// Hook that refreshes every frame (possibly a bit performance heavy)
MAKE_HOOK_MATCH(AnUpdate, &HMMainThreadDispatcher::Update, void, HMMainThreadDispatcher* self)
{
    // Make the wait varible go up by one
    wait = wait + 1;
    AnUpdate(self);

    // A button
    if (getMainConfig().Button.GetValue() == "A Button" || getMainConfig().Button2.GetValue() == "A Button") {

        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::One, OVRInput::Controller::Touch)) {
             getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause() && wait > 120) {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();
                wait = 0;
                return;
            }
        }
    }
    // B button
    if (getMainConfig().Button.GetValue() == "B Button" || getMainConfig().Button2.GetValue() == "B Button") {

        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Two, OVRInput::Controller::Touch)) {
             getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause() && wait > 120) {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();
                wait = 0;
                return;
            }
        }
    }
    // X Button
    if (getMainConfig().Button.GetValue() == "X Button" || getMainConfig().Button2.GetValue() == "X Button") {

        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Three, OVRInput::Controller::Touch)) {
             getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause() && wait > 120) {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();
                wait = 0;
                return;
            }
        }
    }
    // Y Button
    if (getMainConfig().Button.GetValue() == "Y Button" || getMainConfig().Button2.GetValue() == "Y Button") {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Four, OVRInput::Controller::Touch)) {
             getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause() && wait > 120) {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();
                wait = 0;
                return;
            }
        }
    }
    // Left Trigger
    if (getMainConfig().Button.GetValue() == "Left Trigger" || getMainConfig().Button2.GetValue() == "Left Trigger") {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryIndexTrigger, OVRInput::Controller::Touch)) {
             getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause() && wait > 120) {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();
                wait = 0;
                return;
            }
        }
    }
    // Right Trigger
    if (getMainConfig().Button.GetValue() == "Right Trigger" || getMainConfig().Button2.GetValue() == "Right Trigger") {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryIndexTrigger, OVRInput::Controller::Touch)) {
             getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause() && wait > 120) {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();
                wait = 0;
                return;
            }
        }
    }
    // Grip Buttons
    if (getMainConfig().Button.GetValue() == "Left Grip" || getMainConfig().Button.GetValue() == "Left Grip") {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryHandTrigger, OVRInput::Controller::Touch)) {
             getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause() && wait > 120) {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();
                wait = 0;
                return;
            }
        }
    }
    if (getMainConfig().Button.GetValue() == "Right Grip" || getMainConfig().Button2.GetValue() == "Right Grip") {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryHandTrigger, OVRInput::Controller::Touch)) {
             getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause() && wait > 120) {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();
                wait = 0;
                return;
            }
        }
    }
    //right thumb stick
    if (getMainConfig().Button2.GetValue() == "Click Right Thumbstick" || getMainConfig().Button2.GetValue() == "Click Right Thumbstick") {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryThumbstick, OVRInput::Controller::Touch)) {
             getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause() && wait > 120) {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();
                wait = 0;
                return;
            }
        }
    }
    // lrf tumbick
    if (getMainConfig().Button.GetValue() == "Click Left Thumbstick" || getMainConfig().Button2.GetValue() == "Click Left Thumbstick") {
        // Check that the button is pressed
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryThumbstick, OVRInput::Controller::Touch)) {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause()) {
                pauser->paused ? sleep(2), pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();
                wait = 0;
                return;
            }
        }
    }
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info)
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
    // Initialises Quest UI and a gameplay settings menu
    QuestUI::Init();
    QuestUI::Register::RegisterGameplaySetupMenu<PauseRemapper::UI::GameplaySettingsView*>(modInfo, "Pause Remapper");
    // Install Hooks
    getLogger().info("Installing hooks...");
    INSTALL_HOOK(getLogger(), AnUpdate);
    INSTALL_HOOK(getLogger(), SceneChanged);
    getLogger().info("Installed all hooks!");
}