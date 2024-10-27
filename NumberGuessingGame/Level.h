#pragma once

#ifndef _14_50_27_10_2024_LEVEL_H_
#define _14_50_27_10_2024_LEVEL_H_


#include <array>
#include <string>


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

private:
	static constexpr std::array chances{ 10, 7, 5 };

	Type m_type;
	int m_chances;
};


inline std::ostream& operator<<(std::ostream& out, Level::Type type) {
	static const std::array nameLevel{ std::string{ "Easy" },  std::string{ "Medium" },  std::string{ "Hard" } };

	return out << nameLevel[static_cast<std::size_t>(type)];
}

#endif // !_14_50_27_10_2024_LEVEL_H_
