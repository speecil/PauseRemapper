#pragma once
#include "beatsaber-hook/shared/utils/typedefs.h"
#include <string_view>

#include "paper/shared/logger.hpp"

template <>
struct fmt::formatter<std::optional<std::string>> : formatter<string_view>
{
    // parse is inherited from formatter<string_view>.
    template <typename FormatContext>
    auto format(std::optional<std::string> s, FormatContext& ctx)
    {
        return formatter<string_view>::format(s.value_or("NULL"), ctx);
    }
};

static constexpr auto Logger = Paper::ConstLoggerContext("PAUSEREMAPPER");

#define INFO(message, ...) Logger.info(message, ## __VA_ARGS__)
#define ERROR(message, ...) Logger.error(message, ## __VA_ARGS__)
#define WARN(message, ...) Logger.warn(message, ## __VA_ARGS__)
#define CRITICAL(message, ...) Logger.critical(message, ## __VA_ARGS__)
#define DEBUG(message, ...) Logger.debug(message, ## __VA_ARGS__)

using Logger_T = decltype(Logger);