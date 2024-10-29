#pragma once

#include "Level.h"
#include "Result.h"

#include <vector>
#include <string>
#include <string_view>
#include <sstream>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

namespace ResultJsonConverter {
	inline json to_json(const Game::Result& result) {
		return json{
			{ "Chances", result.GetChances() },
			{ "Time", result.GetTime() },
			{ "Type", Game::Level::GetLevelName(result.GetLevelType()) }
		};
	}

	inline json to_json(const std::vector<Game::Result>& results) {
		json j = json::array();
		for (const auto& item : results) {
			j.push_back(to_json(item));
		}

		return j;
	}

	inline std::string Serialize(const std::vector<Game::Result>& results) {
		json j = to_json(results);

		return j.dump(4);
	}

	inline void from_json(const json& j, Game::Result& result) {
		int chances;
		j.at("Chances").get_to(chances);
		std::time_t time;
		j.at("Time").get_to(time);
		Game::Level::Type type;
		std::string str;
		j.at("Type").get_to(str);
		type = Game::Level::GetTypeFromStr(str);

		result = Game::Result{ chances, time, type };
	}

	inline Game::Result Parse(std::string_view str) {
		json j = json::parse(str);
		Game::Result result;

		from_json(j, result);
		return result;
	}

	inline std::vector<Game::Result> ParseArray(std::string_view str) {
		if (str.empty()) {
			return { };
		}

		std::vector<Game::Result> results{ };
		json j = json::parse(str);

		if (j.is_array()) { 
			for (const auto& item : j) {
				Game::Result result;
				from_json(item, result);
				results.push_back(result);
			}
		}

		return results;
	}
}