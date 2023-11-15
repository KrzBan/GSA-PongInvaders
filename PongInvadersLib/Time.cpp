#include "Time.hpp"

#include "SFML/System/Clock.hpp"

namespace gsa {

	struct TimeData {
		sf::Clock gameClock;

		Time::time_t realTime{0};
		Time::time_t deltaTime{0};
	};

	static TimeData s_TimeData;

	Time::time_t Time::DeltaTime() {
		return s_TimeData.deltaTime;
	}
	Time::time_t Time::RealTime() {
		return s_TimeData.realTime;
	}

	void Time::UpdateFrameTime() {
		const auto elapsedTime = s_TimeData.gameClock.getElapsedTime().asSeconds();

		s_TimeData.deltaTime = elapsedTime - s_TimeData.realTime;
		s_TimeData.realTime = elapsedTime;
	}

}