#pragma once

#include "Level.h"
#include <chrono>

namespace Game {

	class Result {
	public:
		Result(int chances, std::time_t time, Level::Type type)
			: m_chances{ chances }
			, m_time{ time }
			, m_type{ type }
		{

		}

		Result() = default;

		operator bool() const { return m_chances > 0; }

		int GetChances() const { return m_chances; }
		std::time_t GetTime() const { return m_time; }
		Level::Type GetLevelType() const { return m_type; }

	private:
		int m_chances{ };
		std::time_t m_time{ };
		Level::Type m_type{ };
	};
}