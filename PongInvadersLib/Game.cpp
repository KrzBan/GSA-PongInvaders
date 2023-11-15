#include "Game.hpp"

#include <format>
#include <iostream>
#include <string_view>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Time.hpp"

namespace gsa {

	void Game::Play() {

        constexpr uint32_t defaultWidth = 800;
        constexpr uint32_t defaultheight = 600;
        constexpr const char*  defaultWindowName = "SFML window";

        sf::RenderWindow window(sf::VideoMode(defaultWidth, defaultheight), defaultWindowName);
        window.setFramerateLimit(60);

        sf::Texture texture;
        if (!texture.loadFromFile("assets/images/cute_image.png"))
            return;
        sf::Sprite sprite(texture);

        // Create a graphical text to display
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/Roboto-Regular.ttf"))
            return;
        sf::Text text("Hello SFML", font, 50);
        text.setColor(sf::Color::Black);

        // sf::View view();
        // window.setView();

        while (window.isOpen()) {
            // Update delta time
            Time::UpdateFrameTime();

            std::cout << std::format("delta:{}, real: {}", Time::DeltaTime(), Time::RealTime()) << '\n';
            
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

            window.draw(sprite);
            window.draw(text);

            // Update the window
            window.display();
        }

        return;

	}

}