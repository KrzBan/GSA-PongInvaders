#include "Game.hpp"

#include <format>
#include <iostream>
#include <string_view>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <spdlog/spdlog.h>

#include "GameObject.hpp"
#include "GameObjects/BackgroundRef.hpp"

#include "Time.hpp"
#include "Utils.hpp"

namespace gsa {

	void Game::Play() {

        constexpr uint32_t defaultWidth = 1600;
        constexpr uint32_t defaultheight = 900;
        constexpr const char*  defaultWindowName = "PongInvaders";

        sf::RenderWindow window(sf::VideoMode(defaultWidth, defaultheight), defaultWindowName, sf::Style::Titlebar | sf::Style::Close);
        window.setFramerateLimit(60);

        sf::View view{{0.0f, 0.0f}, { 1920.0f, 1080.0f }};
        window.setView(view);

        // Background Reference Grid
        BackgroundRef backgroundRef;

        sf::Texture texture;
        Utils::LoadTextureFromFile(texture, "assets/images/cute_image.png");
        sf::Sprite sprite(texture);

        // Create a graphical text to display
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/Roboto-Regular.ttf"))
            return;
        sf::Text text("Hello SFML", font, 50);
        text.setColor(sf::Color::Black);

        while (window.isOpen()) {
            // Update delta time
            Time::UpdateFrameTime();

            //spdlog::info("delta: {}, real: {}", Time::DeltaTime(), Time::RealTime());
            
            // Process events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                
            }

            // Game logic
            // SceneManager::Instance().GetScene().update(delta time);

            // Rendering

            // Clear screen
            window.clear();

            backgroundRef.Render(window);

            window.draw(sprite);
            window.draw(text);

            // Update the window
            window.display();
        }

        return;
	}

}