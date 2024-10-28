#pragma once

#ifndef _20_40_27_10_2024_GAMEUI_H_
#define _20_40_27_10_2024_GAMEUI_H_

#include "Level.h"
#include "Result.h"

#include <array>
#include <string_view>
#include <iostream>

#include <limits>


namespace GameUI {
	void DisplayWelcomeMessage();

	void DisplayLevelsMessage();

	void DisplayStartingGameMessage(const Game::Level& level);

	void DisplayHint(int guess, int targetNumber);

	void DisplayResultMessege(const Game::Result& result);

	void IgnoreLine();

	void HandleInvalidInput(std::string_view message);

	int GetInteger(std::string_view prompt);

	Game::Level GetSelectedLevel();

	int GetGuess();

	bool ShouldContinue();
}


#endif // !_20_40_27_10_2024_GAMEUI_H_

