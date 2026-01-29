cmake_minimum_required(VERSION 3.31)
project(Application)

option(APP_ENABLE_LOGGING "Enables Logging for the Application" ON)

add_executable(Application)

if (APP_ENABLE_LOGGING)
    target_compile_definitions(Application PRIVATE APP_ENABLE_LOGGING)
endif()

set(GLFW_LIBRARY_TYPE STATIC)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_DOCS OFF)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/GLad)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/entt)

target_include_directories(Application 
  PRIVATE 
    "${GLFW_SOURCE_DIR}/include"
    "${glad_SOURCE_DIR}/include"
    "${spdlog_SOURCE_DIR}/include"
    "${EnTT_SOURCE_DIR}/single_include"
)

target_sources(Application
	PRIVATE
	src/main.cpp
    src/Candle/Logger.cpp
)

target_link_libraries(Application
	PRIVATE
	glfw
	glad
)

