add_library(PongInvadersLib)

target_sources(PongInvadersLib PUBLIC
	"Game.hpp" "Game.cpp")

find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

target_include_directories(PongInvadersLib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(PongInvadersLib PUBLIC spdlog::spdlog sfml-system sfml-network sfml-graphics sfml-window sfml-audio)