#include "Game.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace gsa {

	void Game::Play() {

        sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

        sf::Texture texture;
        if (!texture.loadFromFile("assets/images/cute_image.png"))
            return;
        sf::Sprite sprite(texture);

        // Create a graphical text to display
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/Roboto-Regular.ttf"))
            return;
        sf::Text text("Hello SFML", font, 50);

        // sf::View view();
        // window.setView();

        while (window.isOpen()) {
            // Update delta time

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