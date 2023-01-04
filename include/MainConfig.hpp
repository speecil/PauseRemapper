#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(MainConfig,
    CONFIG_VALUE(Button, std::string, "Primary Pause Button", "default");
    CONFIG_VALUE(Button2, std::string, "Secondary Pause Button", "default");
)