#include "PauseRemapperController.hpp"
#include "UnityEngine/Transform.hpp"
#include "GlobalNamespace/IBeatmapLevel.hpp"
#include "UnityEngine/Time.hpp"
#include "questui/shared/BeatSaberUI.hpp"
#include "UnityEngine/Resources.hpp"
#include "UnityEngine/AudioSource.hpp"
#include "MainConfig.hpp"
#include "main.hpp"
#include "GlobalNamespace/OVRInput_Button.hpp"
#include "System/Action.hpp"
#include "questui/shared/CustomTypes/Components/MainThreadScheduler.hpp"

using namespace QuestUI;
DEFINE_TYPE(PauseRemapper, PauseRemapperController);

using namespace UnityEngine;
using namespace System::Threading::Tasks;

namespace PauseRemapper
{
    void PauseRemapperController::ctor(PauseController *pauseController, PauseMenuManager *pauseMenuManager)
    {
        INVOKE_CTOR();
        _pauseController = pauseController;
        _pauseMenuManager = pauseMenuManager;
        getLogger().info("Constructed PauseRemapper Controller");
    }

    void PauseRemapperController::Initialize()
    {
        getLogger().info("Initialised PauseRemapper Controller");
    }

    void PauseRemapperController::Dispose()
    {
        getLogger().info("Disposed PauseRemapper Controller");
    }
    
    void PauseRemapperController::PauseTrigger()
    {
        getLogger().info("A Selected Pause Button Was Clicked/Pressed");
        timeHeld += UnityEngine::Time::get_deltaTime(); // increase time held
        // Check that the user is within gameplay (not menu)
        if (_pauseController && _pauseController->m_CachedPtr.m_value && _pauseController->paused && timeHeld >= 1 && timeHeld < 1.1)
        {
            _pauseMenuManager->ContinueButtonPressed();
        }
        else if (_pauseController && _pauseController->m_CachedPtr.m_value && _pauseController->get_canPause() && timeHeld < 0.6)
        {
            _pauseController->Pause(), getLogger().info("Successfully Paused!");
            _pauseMenuManager->backButton->set_interactable(false);
            _pauseMenuManager->restartButton->set_interactable(false);
            _pauseMenuManager->continueButton->set_interactable(false);

            std::thread([=]()
                {
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            QuestUI::MainThreadScheduler::Schedule([=](){
                _pauseMenuManager->backButton->set_interactable(true);
                _pauseMenuManager->restartButton->set_interactable(true);
                _pauseMenuManager->continueButton->set_interactable(true);
                }); })
            .detach();

        }
        return;
    }

    void PauseRemapperController::Tick()
    {
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
        if (buttonPressed)
        {
            PauseTrigger();
        }
        else
        {
            timeHeld = 0;
        }
        buttonPressed = false;
    }
}