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

	static std::string GetNameLevel(Type type) { return nameLevel[static_cast<std::size_t>(type)]; }

private:
	static constexpr std::array chances{ 10, 7, 5 };
	static constexpr std::array nameLevel{ "Easy", "Medium", "Hard" };

	Type m_type;
	int m_chances;
};

#endif // !_14_50_27_10_2024_LEVEL_H_
