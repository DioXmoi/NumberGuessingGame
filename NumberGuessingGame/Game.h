#pragma once

#ifndef _14_54_27_10_2024_GAME_H_
#define _14_54_27_10_2024_GAME_H_

#include "Random.h"
#include "Level.h"


#include <iostream>
#include <limits>


class Game {
public:

	//The function returns the number of rounds for which the user guessed the number, otherwise 0
	int Play(const Level& level) {
		m_guessNumber = Random::Get(1, 100);
		
		for (int i{ 0 }; i < level.GetNumberChances(); ++i) {
			int number{ GetGlassFromUser() };
			if (IsGuessNumber(number)) {
				return i;
			}

			PrintHint(number);
		}

		return 0;
	}

private:

	bool IsGuessNumber(int number) { return m_guessNumber == number; }

	void PrintHint(int number) {
		if (number > m_guessNumber) {
			std::cout << "Incorrect! The number is less than " << number << ".\n";
		}
		else {
			std::cout << "Incorrect! The number is greater than " << number << ".\n";
		}
	}

	int GetGlassFromUser() {
		while (true) {
			std::cout << "Enter your guess (between 1 and 100): ";

			int number;
			std::cout << "Enter your guess: ";
			std::cin >> number;
			if (std::cin.fail() || number > 100 || number < 1) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Please enter a number between 1 and 100.\n";
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			return number;
		}
	}

private:
	int m_guessNumber;
};

#endif // !_14_54_27_10_2024_GAME_H_

