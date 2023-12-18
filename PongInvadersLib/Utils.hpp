#pragma once

#include <sfml/Graphics/Texture.hpp>

#include <cmath>
#include <format>
#include <stdexcept>

namespace gsa {

	struct Utils {

		static void LoadTextureFromFile(sf::Texture& texture, const std::string& path) {
            if (not texture.loadFromFile(path)) {
                throw std::runtime_error(std::format("Couldn't load texture: {}", path));
            }
        }

        static sf::Vector2f Round(const sf::Vector2f vector)
        {
            return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
        }

	};

}