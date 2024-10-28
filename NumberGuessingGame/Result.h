#pragma once

#include <chrono>

namespace Game {

	class Result {
	public:
		Result(int chances, std::time_t time)
			: m_chances{ chances }
			, m_time{ time }
		{

		}

		operator bool() const { return m_chances > 0; }

		int getChances() const { return m_chances; }
		std::time_t getTime() const { return m_time; }

	private:
		int m_chances{ };
		std::time_t m_time{ };
	};
}