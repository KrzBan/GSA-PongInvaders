cmake_minimum_required (VERSION 3.21)

add_executable (PongInvaders "PongInvaders.cpp" "PongInvaders.h")
target_link_libraries(PongInvaders PUBLIC PongInvadersLib)