#pragma once

#include "../GameObject.hpp"

namespace gsa {
	class PlayerBouncer : public GameObject {
	public:
		PlayerBouncer() {
			SetTexture("assets/images/bouncer.png");

			auto textureBounds = sprite.getLocalBounds();
			sprite.setOrigin(textureBounds.width / 2.f, textureBounds.height / 2.f);
		}
	private:
		float speed = 5.0f;

	public:
		virtual void Update(Time::time_t deltaTime) override {
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				sprite.move(speed* sf::Vector2f{ 0.0f, -1.0f });
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				sprite.move(speed * sf::Vector2f{ 0.0f, 1.0f });
			}

			const auto position = sprite.getPosition();
			sprite.setPosition(
				{ position.x, std::clamp(sprite.getPosition().y, -540.0f, 540.0f) }
			);
		}

	};
}
