#pragma once

#ifndef _14_50_27_10_2024_LEVEL_H_
#define _14_50_27_10_2024_LEVEL_H_

#include <algorithm>
#include <array>
#include <string>

namespace Game {
	class Level {
	public:
		enum Type {
			Easy,
			Medium,
			Hard,
		};

		Level(Type type)
			: m_type{ type }
			, m_chances{ chances[static_cast<std::size_t>(type)] }
		{
		}

		int GetNumberChances() const { return m_chances; }
		Type GetLevelType() const { return m_type; }

		static std::string GetLevelName(Level::Type type) {
			static const std::array nameLevel{ std::string{ "Easy" },  std::string{ "Medium" },  std::string{ "Hard" } };

			return nameLevel[type];
		}

		static Level::Type GetTypeFromStr(const std::string& str) {
			static const std::array nameLevel{ std::string{ "Easy" },  std::string{ "Medium" },  std::string{ "Hard" } };
			auto found{ std::find(nameLevel.begin(), nameLevel.end(), str) };

			if (found != nameLevel.end()) {
				return static_cast<Type>(found - nameLevel.begin());
			}

			throw std::exception("Not found");
		}

	private:
		static constexpr std::array chances{ 10, 7, 5 };

		Type m_type;
		int m_chances;
	};


	inline std::ostream& operator<<(std::ostream& out, Level::Type type) {
		static const std::array nameLevel{ std::string{ "Easy" },  std::string{ "Medium" },  std::string{ "Hard" } };

		return out << Level::GetLevelName(type);
	}
}


#endif // !_14_50_27_10_2024_LEVEL_H_