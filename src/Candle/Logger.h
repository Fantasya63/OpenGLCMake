#pragma once

// #include <stdio.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <memory>

namespace Candle {
    class Log 
    {
    public:
        static void Init();
        
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#ifdef APP_ENABLE_LOGGING
    #define CD_CORE_FATAL(...) Candle::Log::GetCoreLogger()->critical(__VA_ARGS__)
    #define CD_CORE_ERROR(...) Candle::Log::GetCoreLogger()->error(__VA_ARGS__)
    #define CD_CORE_WARN(...) Candle::Log::GetCoreLogger()->warn(__VA_ARGS__)
    #define CD_CORE_INFO(...) Candle::Log::GetCoreLogger()->info(__VA_ARGS__)
    #define CD_CORE_TRACE(...) Candle::Log::GetCoreLogger()->trace(__VA_ARGS__)

    #define CD_FATAL(...) Candle::Log::GetClientLogger()->critical(__VA_ARGS__)
    #define CD_ERROR(...) Candle::Log::GetClientLogger()->error(__VA_ARGS__)
    #define CD_WARN(...) Candle::Log::GetClientLogger()->warn(__VA_ARGS__)
    #define CD_INFO(...) Candle::Log::GetClientLogger()->info(__VA_ARGS__)
    #define CD_TRACE(...) Candle::Log::GetClientLogger()->trace(__VA_ARGS__)
#else
    #define CD_CORE_FATAL(...)
    #define CD_CORE_ERROR(...)
    #define CD_CORE_WARN(...)
    #define CD_CORE_INFO(...)
    #define CD_CORE_TRACE(...)

    #define CD_FATAL(...)
    #define CD_ERROR(...)
    #define CD_WARN(...)
    #define CD_INFO(...)
    #define CD_TRACE(...)
#endif
