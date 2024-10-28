#pragma once

#ifndef _14_54_27_10_2024_GAME_H_
#define _14_54_27_10_2024_GAME_H_

#include "Result.h"
#include "Random.h"
#include "Level.h"
#include "GameUI.h"
#include "chrono"


namespace Game {

	inline bool IsVictory(int number, int targetNumber) { return targetNumber == number; }

	//The function returns the number of rounds for which the user guessed the number, otherwise -1
	Result Play(const Level& level) {
		const int targetNumber = Random::Get(1, 100);
		
		auto start{ std::chrono::system_clock::now() };
		for (int chance{ 0 }; chance < level.GetNumberChances(); ++chance) {
			int guess{ GameUI::GetGuess() };
			if (IsVictory(guess, targetNumber)) {
				auto end{ std::chrono::system_clock::now() };
				std::time_t time{ std::chrono::system_clock::to_time_t(end) - std::chrono::system_clock::to_time_t(start) };
				return Result{ chance, time };
			}

			GameUI::DisplayHint(guess, targetNumber);
		}

		return Result{ -1, -1 };
	}

}

#endif // !_14_54_27_10_2024_GAME_H_

