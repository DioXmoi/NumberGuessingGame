#pragma once

#ifndef _20_40_27_10_2024_GAMEUI_H_
#define _20_40_27_10_2024_GAMEUI_H_

#include "Level.h"

#include <array>
#include <string_view>
#include <iostream>

#include <limits>


namespace GameUI {
	inline void DisplayWelcomeMessage() {
		std::cout << "Welcome to the Number Guessing Game!\n";
		std::cout << "I'm thinking of a number between 1 and 100.\n";
	}

	void DisplayLevelsMessage() {
		std::cout << "\nPlease select the difficulty level:\n\n";
		static const std::array levels{ Level{ Level::Easy }, Level{ Level::Medium }, Level{ Level::Hard } };
		for (std::size_t i{ 0 }; i < levels.size(); ++i) {
			std::cout << i + 1 << ". " << levels[i].GetLevelType() <<
				"(" << levels[i].GetNumberChances() << " chances)\n";
		}
	}

	inline void DisplayStartingGameMessage(const Level& level) {
		std::cout << "\nGreat! You have selected the " <<
			level.GetLevelType() <<
			" difficulty level.\nYou have " <<
			level.GetNumberChances() <<
			" chances to guess the correct number.\n" <<
			"Let's start the game!\n\n";
	}

	inline void DisplayHint(int guess, int targetNumber) {
		if (guess > targetNumber) {
			std::cout << "Incorrect! The number is less than " << guess << ".\n";
		}
		else {
			std::cout << "Incorrect! The number is greater than " << guess << ".\n";
		}
	}

	inline void DisplayResultMessege(int count) {
		if (count > 0) {
			std::cout << "Congratulations! You guessed the correct number in " << count << " attempts.\n";
		}
		else {
			std::cout << "You'll win next time.\n";
		}
	}

	inline void IgnoreLine() {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	void HandleInvalidInput(std::string_view message) {
		std::cin.clear();
		IgnoreLine();
		std::cout << message;
	}

	int GetInteger(std::string_view prompt) {
		while (true) {
			int number;
			std::cout << prompt;
			std::cin >> number;

			if (std::cin.fail()) {
				HandleInvalidInput("Invalid input. Please enter an integer.\n");
				continue;
			}

			IgnoreLine();

			return number;
		}
	}

	Level GetSelectedLevel() {
		while (true) {
			int type{ GetInteger("\nEnter your choice: ")};
			if (type < 1 || type > 3) {
				HandleInvalidInput("Invalid input. Please enter a number between 1 and 3.\n");
				continue;
			}

			return Level{ static_cast<Level::Type>(type - 1) };
		}
	}

	int GetGlass() {
		while (true) {
			std::cout << "Enter your guess (between 1 and 100): ";

			int number{ GetInteger("Enter your guess: ")};
			if (number > 100 || number < 1) {
				HandleInvalidInput("Invalid input. Please enter a number between 1 and 100.\n");
				continue;
			}

			return number;
		}
	}

	bool ShouldContinue() {
		while (true) {
			char ch;
			std::cout << "\nDo you want to play again? (y/n): ";
			std::cin >> ch;
			if (ch == 'y' || ch == 'Y') {
				IgnoreLine();
				return true;
			}
			else if (ch == 'n' || ch == 'N') {
				IgnoreLine();
				return false;
			}
			else {
				HandleInvalidInput("Invalid input. Please enter 'y' or 'n'.\n");
			}
		}
	}
}


#endif // !_20_40_27_10_2024_GAMEUI_H_

