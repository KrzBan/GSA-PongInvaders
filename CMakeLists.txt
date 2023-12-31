﻿cmake_minimum_required (VERSION 3.21)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Vcpkg integration
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

project ("PongInvaders" C CXX)

add_subdirectory(PongInvaders)
add_subdirectory(PongInvadersLib)

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_BINARY_DIR}/PongInvaders/assets
)
add_dependencies(PongInvadersMain copy_assets)

set_property(TARGET PongInvadersMain PROPERTY CXX_STANDARD 20)
set_property(TARGET PongInvadersLib PROPERTY CXX_STANDARD 20)