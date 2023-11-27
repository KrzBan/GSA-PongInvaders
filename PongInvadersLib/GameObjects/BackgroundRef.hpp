#pragma once

#include "../GameObject.hpp"

namespace gsa {
	class BackgroundRef : public GameObject {
	public:
		
		BackgroundRef() {
			SetTexture("assets/images/BG-Grid.png");

			auto textureBounds = sprite.getLocalBounds();
			sprite.setOrigin(textureBounds.width/2.f, textureBounds.height/2.f);
			sprite.setPosition(0.f, 0.f);
			sprite.setColor({ 255, 255, 255, 120 });
		}

		virtual void Update(Time::time_t deltaTime) override {

		}

	};
}
