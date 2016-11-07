cmake_minimum_required(VERSION 3.6)
project(Chromium_simulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/browser_process.hpp
    src/browser_thread.hpp
    src/callback.hpp
    src/channel.hpp
    src/message.hpp
    src/render_process.hpp
    src/render_process_host.hpp src/main.cpp src/channel.cpp src/browser_thread.cpp src/render_process_host.cpp src/render_process.cpp)

add_executable(Chromium_simulator ${SOURCE_FILES})