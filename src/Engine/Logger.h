#pragma once

// #include <stdio.h>
// #include <spdlog/spdlog.h>

#define LOG_CORE_ERROR(...) std::cout << "CORE ERROR: " <<  __VA_ARGS__ << std::endl
#define LOG_CORE_INFO(...) std::cout << "CORE INFO: " << __VA_ARGS__ << std::endl

#define LOG_ERROR(...) std::cout << "APP ERROR: " <<  __VA_ARGS__ << std::endl
#define LOG_INFO(...) std::cout  << "APP INFO: " <<  __VA_ARGS__ << std::endl

