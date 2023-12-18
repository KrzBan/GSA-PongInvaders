#include "Game.hpp"

#include <format>
#include <iostream>
#include <string_view>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <spdlog/spdlog.h>

#include "GameObject.hpp"
#include "GameObjects/BackgroundRef.hpp"
#include "GameObjects/PlayerBouncer.hpp"

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
        PlayerBouncer playerLeft;
        playerLeft.sprite.setPosition({ -900.0f, 0.0f });
        PlayerBouncer playerRight;
        playerRight.sprite.setPosition({ 900.0f, 0.0f });

        // Create a graphical text to display
        sf::Font font;
        std::string fontPath = "assets/fonts/Roboto-Regular.ttf";
        if (!font.loadFromFile(fontPath)) {
            throw std::runtime_error(std::format("Cannot load font: {}", fontPath));
        }

        sf::Text playerScoreLeft("Player Left", font, 50);
        playerScoreLeft.setColor(sf::Color::White);
        {
            auto center = playerScoreLeft.getGlobalBounds().getSize() / 2.f;
            auto localBounds = center + playerScoreLeft.getLocalBounds().getPosition();
            auto rounded = Utils::Round(localBounds);
            playerScoreLeft.setOrigin(rounded);
        }
        playerScoreLeft.setPosition({-300.0f, -500.0f});

        sf::Text playerScoreRight("Player Right", font, 50);
        playerScoreRight.setColor(sf::Color::White);
        {
            auto center = playerScoreRight.getGlobalBounds().getSize() / 2.f;
            auto localBounds = center + playerScoreRight.getLocalBounds().getPosition();
            auto rounded = Utils::Round(localBounds);
            playerScoreRight.setOrigin(rounded);
        }
        playerScoreRight.setPosition({ 300.0f, -500.0f });

        while (window.isOpen()) {
            // Update delta time
            Time::UpdateFrameTime();
            
            // Process events
            sf::Event event;
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // Game logic
            const auto deltaTime = Time::DeltaTime();
            backgroundRef.Update(deltaTime);
            playerLeft.Update(deltaTime);
            playerRight.Update(deltaTime);

            // Rendering
            // Clear screen
            window.clear();

            backgroundRef.Render(window);
            playerLeft.Render(window);
            playerRight.Render(window);

            window.draw(playerScoreLeft);
            window.draw(playerScoreRight);

            // Update the window
            window.display();
        }

        return;
	}

}