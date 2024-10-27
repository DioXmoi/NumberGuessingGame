#pragma once

#ifndef _14_54_27_10_2024_GAME_H_
#define _14_54_27_10_2024_GAME_H_

#include "Random.h"
#include "Level.h"
#include "GameUI.h"


namespace Game {

	inline bool IsVictory(int number, int targetNumber) { return targetNumber == number; }

	//The function returns the number of rounds for which the user guessed the number, otherwise 0
	int Play(const Level& level) {
		const int targetNumber = Random::Get(1, 100);
		
		for (int chance{ 0 }; chance < level.GetNumberChances(); ++chance) {
			int guess{ GameUI::GetGlass() };
			if (IsVictory(guess, targetNumber)) {
				return chance;
			}

			GameUI::DisplayHint(guess, targetNumber);
		}

		return 0;
	}

}

#endif // !_14_54_27_10_2024_GAME_H_

