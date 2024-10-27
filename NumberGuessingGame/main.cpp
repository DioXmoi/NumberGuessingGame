#include "Random.h"
#include "Level.h"
#include "Game.h"

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

int main() {
	std::cout << "Welcome to the Number Guessing Game!\n";
	std::cout << "I'm thinking of a number between 1 and 100.\n";

	const Level level{ PrintAndSelectLevel() };

	std::cout << "\nGreat! You have selected the " <<
		Level::GetNameLevel(level.GetLevelType()) << 
		" difficulty level.\n" << "You have " << level.GetNumberChances() <<
		" chances to guess the correct number.\n" <<
		"Let's start the game!\n\n";

	Game game{ };
	int count{ game.Play(level) };
	if (count > 0) {
		std::cout << "Congratulations! You guessed the correct number in " << count << " attempts.\n";
	}
	else {
		std::cout << "You'll win next time.\n";
	}

	return 0;
}
