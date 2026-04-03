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
set(DGLM_BUILD_TESTS=OFF)
set(DBUILD_SHARED_LIBS=OFF)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/GLad)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/entt)
find_package(glm CONFIG REQUIRED)
target_link_libraries(Application PRIVATE glm::glm)

# add_subdirectory(vendor/assimp)

target_include_directories(Application 
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${GLFW_SOURCE_DIR}/inlude"
    "${glad_SOURCE_DIR}/include"
    "${spdlog_SOURCE_DIR}/include"
    "${EnTT_SOURCE_DIR}/single_include"
    "src/Candle"
)

target_sources(Application
	PRIVATE
	  src/main.cpp
    src/Candle/Logger.cpp
    src/Candle/Core/UUID.cpp
    src/Candle/Scene/Scene.cpp
    src/Candle/Scene/Entity.cpp
    src/Candle/Renderer/Buffer.cpp
    src/Candle/Renderer/Camera.cpp
    src/Candle/Renderer/Camera2D.cpp
    src/Candle/Renderer/Framebuffer.cpp
    src/Candle/Renderer/RenderCommand.cpp
    src/Candle/Renderer/Renderer.cpp
    src/Candle/Renderer/Renderer2D.cpp
    src/Candle/Renderer/RendererAPI.cpp
    src/Candle/Renderer/Shader.cpp
    src/Candle/Renderer/Texture.cpp
    src/Candle/Renderer/VertexArray.cpp
)

target_link_libraries(Application
	PRIVATE
	glfw
	glad
    glm
)

target_precompile_headers(Application
    PRIVATE 
    src/Candle/cdpch.h
)
