#include "Random.h"
#include "Level.h"

#include <array>
#include <string>
#include <iostream>



Level PrintAndSelectLevel() {
	std::cout << "\nPlease select the difficulty level:\n\n";
	static const std::array levels{ Level{ Level::Easy }, Level{ Level::Medium }, Level{ Level::Hard } };
	for (std::size_t i{ 0 }; i < levels.size(); ++i) {
		std::cout << i + 1 << ". " << Level::GetNameLevel(levels[i].GetLevelType()) << 
			"(" << levels[i].GetNumberChances() << " chances)\n";
	}

	//Добавить валидацию входных данных.
	int out;
	std::cout << "\nEnter your choice: ";
	std::cin >> out;

	return Level{ static_cast<Level::Type>(out - 1) };
}

//Написать что return это количество попыток 
int PlayGame(const Level& level) {
	const int guessNumber{ Random::Get(1, 100) };
	//Разбить код на функции.
	for (int i{ 0 }; i < level.GetNumberChances(); ++i) {
		int number;
		std::cout << "Enter your guess: ";
		std::cin >> number;
		if (number == guessNumber) {
			return i;
		}

		if (number > guessNumber) {
			std::cout << "Incorrect! The number is less than " << number << ".\n";
		}
		else {
			std::cout << "Incorrect! The number is greater than " << number << ".\n";
		}
	}

	return 0;
}

int main() {
	std::cout << "Welcome to the Number Guessing Game!\n";
	std::cout << "I'm thinking of a number between 1 and 100.\n";

	const Level level{ PrintAndSelectLevel() };

	std::cout << "\nGreat! You have selected the " <<
		Level::GetNameLevel(level.GetLevelType()) << 
		" difficulty level.\n" << "You have " << level.GetNumberChances() <<
		" chances to guess the correct number.\n" <<
		"Let's start the game!\n\n";

	int count{ PlayGame(level) };
	if (count > 0) {
		std::cout << "Congratulations! You guessed the correct number in " << count << " attempts.\n";
	}
	else {
		std::cout << "You'll win next time.\n";
	}

	return 0;
}
