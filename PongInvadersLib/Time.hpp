#pragma once

#include <sfml/System/Time.hpp>

namespace gsa {

	struct Time {

		using time_t = float;

	public:
		static time_t DeltaTime();
		static time_t RealTime();

		static void UpdateFrameTime();
	};

}