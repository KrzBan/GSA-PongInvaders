#pragma once

#include <SFML/Graphics.hpp>

#include "Time.hpp"
#include "Utils.hpp"

namespace gsa {

	class GameObject {

	public:
		GameObject()
			:sprite{ texture } {}
		virtual ~GameObject() = default;

		void SetTexture(const std::string& texturePath) {
			Utils::LoadTextureFromFile(texture, texturePath);
			sprite.setTexture(texture, true);
		}

	public:
		sf::Texture texture;
		sf::Sprite sprite;

	public:
		void Render(sf::RenderWindow& window) {
			window.draw(sprite);
		}

		virtual void Update(Time::time_t deltaTime) = 0;
	};

}


