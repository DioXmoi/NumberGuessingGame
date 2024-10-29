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
		int m_chances{  };
		std::time_t m_time{ };
		Level::Type m_type{ };
	};

	inline Result FindBest(const std::vector<Result>& results, Level::Type type) {
		auto it = std::ranges::min_element(results,
			[type](const auto& a, const auto& b) {
				return a.GetLevelType() == type && a.GetChances() < b.GetChances();
			});

		return it != results.end() ? *it : Game::Result{};
	}

	inline std::vector<Result> FindBestResults(const std::vector<Result>& results) {
		static const std::array type{ Level::Easy, Level::Medium, Level::Hard };

		std::vector<Result> best{ };
		for (const auto& item : type) {
			Result res{ FindBest(results, item) };
			if (res) {
				best.push_back(res);
			}
		}

		return best;
	}
}