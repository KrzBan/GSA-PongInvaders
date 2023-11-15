cmake_minimum_required (VERSION 3.21)

add_executable (PongInvadersMain "PongInvaders.cpp" "PongInvaders.hpp")
target_link_libraries(PongInvadersMain PUBLIC PongInvadersLib)