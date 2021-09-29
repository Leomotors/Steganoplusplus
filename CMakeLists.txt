cmake_minimum_required(VERSION 3.16)
project(Steganoplusplus VERSION 1.0.3)

set(EXECUTABLE_NAME "Sgpp")

# Config
set(APP_VERSION "${CMAKE_PROJECT_VERSION}")
configure_file(config/AppProps.h.in ${CMAKE_CURRENT_BINARY_DIR}/gen/AppProps.h)

# Import OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# SRC FILE
file(GLOB APP_SRC "src/*.cpp")
include_directories(src)

# Compiling
add_executable(${EXECUTABLE_NAME} ${APP_SRC})

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3 -lm")

# Linking Libraries for main
target_link_libraries(${EXECUTABLE_NAME} ${OpenCV_LIBS})
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/gen)

# CPP STANDARD
set_property(TARGET ${EXECUTABLE_NAME} PROPERTY CXX_STANDARD 20)

# Install
install(
    TARGETS ${EXECUTABLE_NAME}
    RUNTIME DESTINATION /usr/local/bin
)
