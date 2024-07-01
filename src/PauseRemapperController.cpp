#include "PauseRemapperController.hpp"
#include "UnityEngine/Transform.hpp"
#include "UnityEngine/Time.hpp"
#include "UnityEngine/Resources.hpp"
#include "UnityEngine/AudioSource.hpp"
#include "MainConfig.hpp"
#include "main.hpp"
#include "GlobalNamespace/OVRInput.hpp"
#include "Logging.hpp"
#include "System/Action.hpp"
#include "lapiz/shared/utilities/MainThreadScheduler.hpp"

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
        INFO("Constructed PauseRemapper Controller");
    }

    void PauseRemapperController::Initialize()
    {
        INFO("Initialised PauseRemapper Controller");
    }

    void PauseRemapperController::Dispose()
    {
        INFO("Disposed PauseRemapper Controller");
    }
    
    void PauseRemapperController::PauseTrigger()
    {
        INFO("A Selected Pause Button Was Clicked/Pressed");
        timeHeld += UnityEngine::Time::get_deltaTime(); // increase time held
        // Check that the user is within gameplay (not menu)
        if (_pauseController && _pauseController->___m_CachedPtr.m_value && _pauseController->____paused && timeHeld >= 1 && timeHeld < 1.1)
        {
            _pauseMenuManager->ContinueButtonPressed();
        }
        else if (_pauseController && _pauseController->___m_CachedPtr.m_value && _pauseController->get_canPause() && timeHeld < 0.6)
        {
            _pauseController->Pause(), INFO("Successfully Paused!");
            _pauseMenuManager->____backButton->set_interactable(false);
            _pauseMenuManager->____restartButton->set_interactable(false);
            _pauseMenuManager->____continueButton->set_interactable(false);

            std::thread([=]()
                {
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            Lapiz::Utilities::MainThreadScheduler::Schedule([=](){
                _pauseMenuManager->____backButton->set_interactable(true);
                _pauseMenuManager->____restartButton->set_interactable(true);
                _pauseMenuManager->____continueButton->set_interactable(true);
                }); })
            .detach();

        }
        return;
    }

    #include <unordered_map>
    std::unordered_map<bool, GlobalNamespace::OVRInput::Button> buttonMapping = {
        {getMainConfig().aButton.GetValue(), GlobalNamespace::OVRInput::Button::One},
        {getMainConfig().bButton.GetValue(), GlobalNamespace::OVRInput::Button::Two},
        {getMainConfig().xButton.GetValue(), GlobalNamespace::OVRInput::Button::Three},
        {getMainConfig().yButton.GetValue(), GlobalNamespace::OVRInput::Button::Four},
        {getMainConfig().leftTrigger.GetValue(), GlobalNamespace::OVRInput::Button::PrimaryIndexTrigger},
        {getMainConfig().rightTrigger.GetValue(), GlobalNamespace::OVRInput::Button::SecondaryIndexTrigger},
        {getMainConfig().leftGrip.GetValue(), GlobalNamespace::OVRInput::Button::PrimaryHandTrigger},
        {getMainConfig().rightGrip.GetValue(), GlobalNamespace::OVRInput::Button::SecondaryHandTrigger},
        {getMainConfig().leftThumbstick.GetValue(), GlobalNamespace::OVRInput::Button::SecondaryThumbstick},
        {getMainConfig().rightThumbstick.GetValue(), GlobalNamespace::OVRInput::Button::PrimaryThumbstick}
    };
    
    void PauseRemapperController::Tick()
    {
        for (const auto& button : buttonMapping)
        {
            if (button.first && GlobalNamespace::OVRInput::Get(button.second, OVRInput::Controller::Touch))
            {
                buttonPressed = true;
                break;
            }
        }

        if (buttonPressed) PauseTrigger();
        else timeHeld = 0;
        buttonPressed = false;
    }   
}