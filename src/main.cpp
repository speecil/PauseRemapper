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
using namespace PauseRemapper::UI;
using namespace GlobalNamespace;
using namespace QuestUI;
using namespace UnityEngine;
PauseController *pauser;
PauseMenuManager *pauseMENU;
float timeHeld;
bool inGameplay;

bool buttonPressed;

std::string failReason;

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Returns a logger, useful for printing debug messages
Logger &getLogger()
{
    static Logger *logger = new Logger(modInfo);
    return *logger;
}

void BroPaused()
{
    getLogger().info("A Selected Pause Button Was Clicked/Pressed");
    timeHeld += UnityEngine::Time::get_deltaTime(); // increase time held
    // Check that the user is within gameplay (not menu)
    if (pauser && pauser->m_CachedPtr.m_value && pauser->paused && timeHeld >= 1 && timeHeld < 1.5)
    {
        pauseMENU->didPressContinueButtonEvent->Invoke();
    }
    else if (inGameplay && pauser && pauser->m_CachedPtr.m_value && pauser->get_canPause())
    {
        pauser->Pause(), getLogger().info("Successfully Paused!");
    }
    return;
}

// Hook for seeing what scene the game is currently in
MAKE_HOOK_MATCH(SceneChanged, &UnityEngine::SceneManagement::SceneManager::Internal_ActiveSceneChanged, void, UnityEngine::SceneManagement::Scene prevScene, UnityEngine::SceneManagement::Scene nextScene)
{
    SceneChanged(prevScene, nextScene);
    // Check that the scene is primary gameplay
    if (nextScene && nextScene.get_name() == "GameCore")
    {
        inGameplay = true;
        failReason = "UNKNOWN EXCEPTION";
        // Find both unity objects of *PauseController* and *PauseMenuManager* and assign them to pauser, pauseMENU
        pauser = UnityEngine::Resources::FindObjectsOfTypeAll<PauseController *>().FirstOrDefault();
        pauseMENU = UnityEngine::Resources::FindObjectsOfTypeAll<PauseMenuManager *>().FirstOrDefault();
    }
    else
    {
        inGameplay = false;
        failReason = "Being In Menu";
    }
}

// Hook that refreshes every frame (possibly a bit performance heavy)
MAKE_HOOK_MATCH(AnUpdate, &HMMainThreadDispatcher::Update, void, HMMainThreadDispatcher *self)
{
    AnUpdate(self);
    buttonPressed = false;
    // A button lmfao
    if (getMainConfig().aButton.GetValue())
    {

        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::One, OVRInput::Controller::Touch))
        {
            buttonPressed = true;
        }

    }
    // B button
    if (getMainConfig().bButton.GetValue())
    {

        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Two, OVRInput::Controller::Touch))
        {
            buttonPressed = true;
        }

    }

    // X Button
    if (getMainConfig().xButton.GetValue())
    {

        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Three, OVRInput::Controller::Touch))
        {
            buttonPressed = true;
        }

    }
    // Y Button
    if (getMainConfig().yButton.GetValue())
    {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::Four, OVRInput::Controller::Touch))
        {
            buttonPressed = true;
        }

    }
    // Left Trigger
    if (getMainConfig().leftTrigger.GetValue())
    {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryIndexTrigger, OVRInput::Controller::Touch))
        {
            buttonPressed = true;
        }

    }
    // Right Trigger
    if (getMainConfig().rightTrigger.GetValue())
    {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryIndexTrigger, OVRInput::Controller::Touch))
        {
            buttonPressed = true;
        }

    }
    // Grip Buttons
    if (getMainConfig().leftGrip.GetValue())
    {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryHandTrigger, OVRInput::Controller::Touch))
        {
            buttonPressed = true;
        }

    }
    if (getMainConfig().rightGrip.GetValue())
    {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryHandTrigger, OVRInput::Controller::Touch))
        {
            buttonPressed = true;
        }

    }
    // left thumb stick
    if (getMainConfig().leftThumbstick.GetValue())
    {
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::SecondaryThumbstick, OVRInput::Controller::Touch))
        {
            buttonPressed = true;
        }

    }
    // right tumbick
    if (getMainConfig().rightThumbstick.GetValue())
    {
        // Check that the button is pressed
        if (GlobalNamespace::OVRInput::Get(GlobalNamespace::OVRInput::Button::PrimaryThumbstick, OVRInput::Controller::Touch))
        {
            buttonPressed = true;
        }
        

    }
    if(buttonPressed){
        BroPaused();
    }
    else{
        timeHeld = 0;
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