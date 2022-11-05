#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(MainConfig,
    CONFIG_VALUE(EnableResume, bool, "Enable Resuming with the selected button?", false);
    CONFIG_VALUE(Button, std::string, "Primary Pause Button", "default");
    CONFIG_VALUE(Button2, std::string, "Secondary Pause Button", "default");


    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(Button);
        CONFIG_INIT_VALUE(Button2);        
        CONFIG_INIT_VALUE(EnableResume);
    )
)