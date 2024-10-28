#include "GameUI.h"


#include <array>
#include <iostream>
#include <limits>
#include <string_view>


void GameUI::DisplayWelcomeMessage() {
	std::cout << "Welcome to the Number Guessing Game!\n";
	std::cout << "I'm thinking of a number between 1 and 100.\n";
}


void GameUI::DisplayLevelsMessage() {
	std::cout << "\nPlease select the difficulty level:\n\n";
	static const std::array levels{ Game::Level{ Game::Level::Easy }, Game::Level{ Game::Level::Medium }, Game::Level{ Game::Level::Hard } };
	for (std::size_t i{ 0 }; i < levels.size(); ++i) {
		std::cout << i + 1 << ". " << levels[i].GetLevelType() <<
			"(" << levels[i].GetNumberChances() << " chances)\n";
	}
}


void GameUI::DisplayStartingGameMessage(const Game::Level& level) {
	std::cout << "\nGreat! You have selected the " <<
		level.GetLevelType() <<
		" difficulty level.\nYou have " <<
		level.GetNumberChances() <<
		" chances to guess the correct number.\n" <<
		"Let's start the game!\n\n";
}


void  GameUI::DisplayHint(int guess, int targetNumber) {
	if (guess > targetNumber) {
		std::cout << "Incorrect! The number is less than " << guess << ".\n";
	}
	else {
		std::cout << "Incorrect! The number is greater than " << guess << ".\n";
	}
}


void GameUI::DisplayResultMessege(const Game::Result& result) {
	if (result) {
		std::cout << "Congratulations! You guessed the correct number in " << result.getChances() <<
			" attempts.\nAnd it took you " << result.getTime() << " seconds.\n";
	}
	else {
		std::cout << "You'll win next time.\n";
	}
}


void GameUI::IgnoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void GameUI::HandleInvalidInput(std::string_view message) {
	std::cin.clear();
	IgnoreLine();
	std::cout << message;
}


int GameUI::GetInteger(std::string_view prompt) {
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


Game::Level GameUI::GetSelectedLevel() {
	while (true) {
		int type{ GetInteger("\nEnter your choice: ") };
		if (type < 1 || type > 3) {
			std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
			continue;
		}

		return Game::Level{ static_cast<Game::Level::Type>(type - 1) };
	}
}


int GameUI::GetGuess() {
	while (true) {
		std::cout << "Enter your guess (between 1 and 100): ";

		int number{ GetInteger("Enter your guess: ") };
		if (number > 100 || number < 1) {
			std::cout << "Invalid input. Please enter a number between 1 and 100.\n";
			continue;
		}

		return number;
	}
}


bool GameUI::ShouldContinue() {
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