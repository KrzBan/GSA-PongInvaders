#pragma once

#include <sfml/Graphics/Texture.hpp>

namespace gsa {

	struct Utils {

		static void LoadTextureFromFile(sf::Texture& texture, const std::string& path) {
            if (not texture.loadFromFile(path)) {
                throw std::runtime_error(std::format("Couldn't load texture: {}", path));
            }
        }

	};

}