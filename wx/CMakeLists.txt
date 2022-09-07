cmake_minimum_required(VERSION 3.2)
project(wxGameOfLife)

set(CMAKE_CXX_STANDARD 17)

# TODO: Probably need to add dependencies into this folder to be able to install it everywhere e.g. ./libs/
# Can be used with add_subdirectory(...)
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/wxwidgets/3.2.0_1")
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(wxGameOfLife ../lib/board.cpp GameButton.cpp GOLWindow.cpp GOLApp.cpp main.cpp)
target_link_libraries(wxGameOfLife ${wxWidgets_LIBRARIES})
