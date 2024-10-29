#include "File.h"
#include "Game.h"
#include "GameUI.h"
#include "Level.h"
#include "Result.h"
#include "ResultJsonConverter.h"

#include <vector>
#include <string>

int main() {
	GameUI::DisplayWelcomeMessage();

	File file{ "BestResults.json" };
	std::vector<Game::Result> results{ 
		ResultJsonConverter::ParseArray(file.read()) };

	do {
		GameUI::DisplayLevelsMessage();

		//Print best result.

		const Game::Level level{ GameUI::GetSelectedLevel() };

		GameUI::DisplayStartingGameMessage(level);
	
		auto result{ Game::Play(level) };

		results.push_back(result);
		GameUI::DisplayResultMessege(result);

	} while (GameUI::ShouldContinue());

	file.write(ResultJsonConverter::Serialize(results));

	return 0;
}