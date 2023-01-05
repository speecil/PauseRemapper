#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(MainConfig,
    CONFIG_VALUE(aButton, bool, "A Button", false);
    CONFIG_VALUE(bButton, bool, "B Button", false);
    CONFIG_VALUE(xButton, bool, "X Button", false);
    CONFIG_VALUE(yButton, bool, "Y Button", false);
    CONFIG_VALUE(leftTrigger, bool, "Left Trigger", false);
    CONFIG_VALUE(rightTrigger, bool, "Left Trigger", false);
    CONFIG_VALUE(leftGrip, bool, "Left Grip", false);
    CONFIG_VALUE(rightGrip, bool, "Right Grip", false);
    CONFIG_VALUE(leftThumbstick, bool, "Left Thumbstick", false);
    CONFIG_VALUE(rightThumbstick, bool, "Right Thumbstick", false);
    CONFIG_VALUE(moveLThumbstick, bool, "Move Left Thumbstick", false);
    CONFIG_VALUE(moveRThumbstick, bool, "Move Right Thumbstick", false);
)