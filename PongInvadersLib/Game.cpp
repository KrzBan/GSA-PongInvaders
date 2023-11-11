#include "Game.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace gsa {

	void Game::Play() {

        // Create the main window
        sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

        // Load a sprite to display
        sf::Texture texture;
        if (!texture.loadFromFile("assets/images/cute_image.png"))
            return;
        sf::Sprite sprite(texture);

        // Create a graphical text to display
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/Roboto-Regular.ttf"))
            return;
        sf::Text text("Hello SFML", font, 50);

        // Load a music to play
        // sf::Music music;
        // if (!music.openFromFile("nice_music.ogg"))
        //     return;
        // 
        // // Play the music
        // music.play();

        // Start the game loop
        while (window.isOpen())
        {
            // Process events
            sf::Event event;
            while (window.pollEvent(event))
            {
                // Close window: exit
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // Clear screen
            window.clear();

            // Draw the sprite
            window.draw(sprite);

            // Draw the string
            window.draw(text);

            // Update the window
            window.display();
        }

        return;

	}

}