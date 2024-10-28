#include "Game.h"
#include "Random.h"
#include "GameUI.h"

static inline bool IsVictory(int number, int targetNumber) { return targetNumber == number; }

Game::Result Game::Play(const Game::Level& level) {
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