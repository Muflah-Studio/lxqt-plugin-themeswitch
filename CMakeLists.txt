# CMake build definition
# SPDX-FileCopyrightText: 2025 <copyright holder> <email>
# SPDX-License-Identifier: GPL-2.0-or-later

# Minimum required CMake version
cmake_minimum_required(VERSION 3.16)

# Project information
project(lqxt-themeswitcher VERSION 0.0.1 LANGUAGES CXX)

# Find necessary packages
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

# Set the standard for C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

include(GNUInstallDirs)

set(PLUGIN_ID "themeswitcher")
set(PLUGIN_VERSION "0.0.1")

set(PLUGIN_LIB_DIR "${CMAKE_INSTALL_FULL_LIBDIR}/lxqt-panel/")
set(PLUGIN_DESKTOP_DIR "${CMAKE_INSTALL_FULL_DATAROOTDIR}/lxqt/lxqt-panel/")

set(QT_INCLUDE_DIRS "")
set(QT_LIBRARIES "")
foreach(temp Core Gui Widgets)
    list(APPEND QT_INCLUDE_DIRS "${Qt5${temp}_INCLUDE_DIRS}")
    list(APPEND QT_LIBRARIES "${Qt5${temp}_LIBRARIES}")
endforeach()
include_directories(${QT_INCLUDE_DIRS})

# Add the source files for the plugin library
add_library(plugin MODULE
    src/lxqtthemeswitcher.h
    src/themeswitcherbutton.h
    src/lxqtthemeswitcher.cpp
    src/themeswitcherbutton.cpp)

# Link the plugin with dependencies
target_link_libraries(plugin ${QT_LIBRARIES})

# Set necessary properties for the plugin
set_target_properties(plugin PROPERTIES OUTPUT_NAME ${PLUGIN_ID})

# Install the plugin to the correct LXQt directory
install(TARGETS plugin DESTINATION ${PLUGIN_LIB_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/themeswitcher.desktop
    DESTINATION ${PLUGIN_DESKTOP_DIR})
