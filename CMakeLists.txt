cmake_minimum_required(VERSION 3.31)
project(Application)

add_executable(Application)

set(GLFW_LIBRARY_TYPE STATIC)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_DOCS OFF)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/GLad)

target_include_directories(Application 
  PRIVATE 
    "${GLFW_SOURCE_DIR}/include"
    "${glad_SOURCE_DIR}/include"
  INTERFACE
    src/Engine/
)

target_sources(Application
	PRIVATE
	src/main.cpp
)

target_link_libraries(Application
	PRIVATE
	glfw
	glad
)
