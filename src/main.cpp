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

using namespace PauseRemapper::UI;
using namespace GlobalNamespace;
using namespace QuestUI;
PauseController *pauser;
PauseMenuManager *pauseMENU;
bool test = true;
int shouldpause;
bool inGameplay;
bool paused;
bool alreadyPressed;

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Returns a logger, useful for printing debug messages
Logger &getLogger()
{
    static Logger *logger = new Logger(modInfo);
    return *logger;
}

// Hook for seeing what scene the game is currently in
MAKE_HOOK_MATCH(SceneChanged, &UnityEngine::SceneManagement::SceneManager::Internal_ActiveSceneChanged, void, UnityEngine::SceneManagement::Scene prevScene, UnityEngine::SceneManagement::Scene nextScene)
{
    SceneChanged(prevScene, nextScene);
    // Check that the scene is primary gameplay
    if (nextScene && nextScene.get_name() == "GameCore")
    {
        // if in primary gameplay, then set the bools accordingly
        inGameplay = true;
        paused = false;
        // Find both unity objects of *PauseController* and *PauseMenuManager* and assign them to pauser, pauseMENU
        pauser = UnityEngine::Resources::FindObjectsOfTypeAll<PauseController *>().FirstOrDefault();
        pauseMENU = UnityEngine::Resources::FindObjectsOfTypeAll<PauseMenuManager *>().FirstOrDefault();
    }
    else
        inGameplay = false;
}

// Hook that refreshes every frame (possibly a bit performance heavy)
MAKE_HOOK_MATCH(AnUpdate, &HMMainThreadDispatcher::Update, void, HMMainThreadDispatcher *self)
{
    AnUpdate(self);

    // A button lmfao
    if (getMainConfig().aButton.GetValue())
    {

        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::One, OVRInput::Controller::Touch))
        {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
            {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();

                return;
            }
        }
    }
    // B button
    if (getMainConfig().bButton.GetValue())
    {

        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Two, OVRInput::Controller::Touch))
        {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
            {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();

                return;
            }
        }
    }
    // X Button
    if (getMainConfig().xButton.GetValue())
    {

        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Three, OVRInput::Controller::Touch))
        {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
            {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();

                return;
            }
        }
    }
    // Y Button
    if (getMainConfig().yButton.GetValue())
    {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Four, OVRInput::Controller::Touch))
        {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
            {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();

                return;
            }
        }
    }
    // Left Trigger
    if (getMainConfig().leftTrigger.GetValue())
    {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryIndexTrigger, OVRInput::Controller::Touch))
        {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
            {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();

                return;
            }
        }
    }
    // Right Trigger
    if (getMainConfig().rightTrigger.GetValue())
    {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryIndexTrigger, OVRInput::Controller::Touch))
        {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
            {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();

                return;
            }
        }
    }
    // Grip Buttons
    if (getMainConfig().leftGrip.GetValue())
    {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryHandTrigger, OVRInput::Controller::Touch))
        {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
            {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();

                return;
            }
        }
    }
    if (getMainConfig().rightGrip.GetValue())
    {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryHandTrigger, OVRInput::Controller::Touch))
        {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
            {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();

                return;
            }
        }
    }
    // left thumb stick
    if (getMainConfig().leftThumbstick.GetValue())
    {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryThumbstick, OVRInput::Controller::Touch))
        {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
            {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();

                return;
            }
        }
    }
    // right tumbick
    if (getMainConfig().rightThumbstick.GetValue())
    {
        // Check that the button is pressed
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryThumbstick, OVRInput::Controller::Touch))
        {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
            {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();

                return;
            }
        }
    }
    ///////
    // left thumb stick MOVE
    if (getMainConfig().leftThumbstick.GetValue())
    {
        // Check that the button is pressed
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryThumbstickDown, OVRInput::Controller::Touch) || GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryThumbstickUp, OVRInput::Controller::Touch) || GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryThumbstickLeft, OVRInput::Controller::Touch) || GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryThumbstickRight, OVRInput::Controller::Touch))
        {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
            {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();

                return;
            }
        }
    }
    // right tumbick MOVE
    if (getMainConfig().rightThumbstick.GetValue())
    {
        // Check that the button is pressed
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryThumbstickDown, OVRInput::Controller::Touch) || GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryThumbstickUp, OVRInput::Controller::Touch) || GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryThumbstickLeft, OVRInput::Controller::Touch) || GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryThumbstickRight, OVRInput::Controller::Touch))
        {
            getLogger().info("Selected Button Clicked");
            // Check that the user is within gameplay (not menu)
            if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
            {
                pauser->paused ? pauseMENU->didPressContinueButtonEvent->Invoke() : pauser->Pause();

                return;
            }
        }
    }
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
    // Install Hooks
    getLogger().info("Installing hooks...");
    INSTALL_HOOK(getLogger(), AnUpdate);
    INSTALL_HOOK(getLogger(), SceneChanged);
    getLogger().info("Installed all hooks!");
}

BSML_DATACACHE(settings)
{
    return IncludedAssets::settings_bsml;
}