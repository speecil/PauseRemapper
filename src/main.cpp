#include "main.hpp"
#include "questui/shared/QuestUI.hpp"
#include "config-utils/shared/config-utils.hpp"
#include "GlobalNamespace/OVRInput_Button.hpp"
#include "GlobalNamespace/PauseController.hpp"
#include "MainConfig.hpp"
#include "GlobalNamespace/HMMainThreadDispatcher.hpp"
#include "UI/PauseRemapperFlowCoordinator.hpp"
using namespace GlobalNamespace;
using namespace QuestUI;
const std::vector<OVRInput::Button> buttons = {
    OVRInput::Button::One,
    OVRInput::Button::Two,
    OVRInput::Button::Three,
    OVRInput::Button::Four,
};
GlobalNamespace::PauseController* pauser;
int shouldpause = 0;

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

    for(auto button : buttons){
    bool abutton = OVRInput::GetDown(button, OVRInput::Button::One);
    bool bbutton = OVRInput::GetDown(button, OVRInput::Button::Two);
    bool xbutton = OVRInput::GetDown(button, OVRInput::Button::Three);
    bool ybutton = OVRInput::GetDown(button, OVRInput::Button::Four);

    if(getMainConfig().isEnabled.GetValue()){
    // default button
    if(getMainConfig().Button.GetValue() == "default"){

    }
    // A Button
    if(getMainConfig().Button.GetValue() == "abutton"){
        if(abutton){
            shouldpause = 1;
        }
    }
    else{
        shouldpause = 0;
    }
    // B Button
    if(getMainConfig().Button.GetValue() == "bbutton"){
        if(bbutton){
            shouldpause = 1;
        }
    }
    else{
        shouldpause = 0;
    }
    // X Button
    if(getMainConfig().Button.GetValue() == "xbutton"){
        if(xbutton){
            shouldpause = 1;
        }
    }
    else{
        shouldpause = 0;
    }
    // Y Button
    if(getMainConfig().Button.GetValue() == "ybutton"){
        if(ybutton){
            shouldpause = 1;
        }
    }
    else{
        shouldpause = 0;
    }
}


    switch (shouldpause) {
        
        case 0:
            break;

        case 1:
            getLogger().info("pause");
            pauser->Pause();
            break;
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
    // Install our hooks (none defined yet)
    getLogger().info("Installed all hooks!");
}