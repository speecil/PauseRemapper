#include "main.hpp"
#include "UI/UIManager.hpp"

#include "MainConfig.hpp"

#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerSpecificSettings.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/WaitForSeconds.hpp"
#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DEFINE_TYPE(PauseRemapper::UI, UIManager);

namespace PauseRemapper::UI
{
    SafePtr<UIManager> UIManager::instance;
    UIManager *UIManager::get_instance()
    {
        if (!instance)
            instance = UIManager::New_ctor();
        return instance.ptr();
    }
    void UIManager::ctor() {}
    // abxy
    bool UIManager::get_aButton() { return getMainConfig().aButton.GetValue(); }
    void UIManager::set_aButton(bool value)
    {
        getMainConfig().aButton.SetValue(value);
    }
    bool UIManager::get_bButton() { return getMainConfig().bButton.GetValue(); }
    void UIManager::set_bButton(bool value)
    {
        getMainConfig().bButton.SetValue(value);
    }
    bool UIManager::get_xButton() { return getMainConfig().xButton.GetValue(); }
    void UIManager::set_xButton(bool value)
    {
        getMainConfig().xButton.SetValue(value);
    }
    bool UIManager::get_yButton() { return getMainConfig().yButton.GetValue(); }
    void UIManager::set_yButton(bool value)
    {
        getMainConfig().yButton.SetValue(value);
    }

    bool UIManager::get_leftThumbstick() { return getMainConfig().leftThumbstick.GetValue(); }
    void UIManager::set_leftThumbstick(bool value)
    {
        getMainConfig().leftThumbstick.SetValue(value);
    }
    bool UIManager::get_rightThumbstick() { return getMainConfig().rightThumbstick.GetValue(); }
    void UIManager::set_rightThumbstick(bool value)
    {
        getMainConfig().rightThumbstick.SetValue(value);
    }
    bool UIManager::get_moveLThumbstick() { return getMainConfig().moveLThumbstick.GetValue(); }
    void UIManager::set_moveLThumbstick(bool value)
    {
        getMainConfig().moveLThumbstick.SetValue(value);
    }
    bool UIManager::get_moveRThumbstick() { return getMainConfig().moveRThumbstick.GetValue(); }
    void UIManager::set_moveRThumbstick(bool value)
    {
        getMainConfig().moveRThumbstick.SetValue(value);
    }

    bool UIManager::get_leftTrigger() { return getMainConfig().leftTrigger.GetValue(); }
    void UIManager::set_leftTrigger(bool value)
    {
        getMainConfig().leftTrigger.SetValue(value);
    }
    bool UIManager::get_rightTrigger() { return getMainConfig().rightTrigger.GetValue(); }
    void UIManager::set_rightTrigger(bool value)
    {
        getMainConfig().rightTrigger.SetValue(value);
    }
    bool UIManager::get_leftGrip() { return getMainConfig().leftGrip.GetValue(); }
    void UIManager::set_leftGrip(bool value)
    {
        getMainConfig().leftGrip.SetValue(value);
    }
    bool UIManager::get_rightGrip() { return getMainConfig().rightGrip.GetValue(); }
    void UIManager::set_rightGrip(bool value)
    {
        getMainConfig().rightGrip.SetValue(value);
    }

}