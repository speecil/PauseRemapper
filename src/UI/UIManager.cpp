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

    StringW UIManager::get_Button1() { return getMainConfig().Button.GetValue(); }
    void UIManager::set_Button1(StringW value)
    {
        value->ToString();
        getMainConfig().Button.SetValue(value, false);
    }
    StringW UIManager::get_Button2() { return getMainConfig().Button2.GetValue(); }
    void UIManager::set_Button2(StringW value)
    {
        value->ToString();
        getMainConfig().Button2.SetValue(value, false);
    }

}