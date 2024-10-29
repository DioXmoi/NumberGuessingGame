#include "File.h"
#include "Game.h"
#include "GameUI.h"
#include "Level.h"
#include "Result.h"
#include "ResultJsonConverter.h"

#include <algorithm>
#include <vector>
#include <string>



int main() {
	GameUI::DisplayWelcomeMessage();

	File file{ "BestResults.json" };
	std::vector<Game::Result> bestResults{ 
		Game::FindBestResults(ResultJsonConverter::ParseArray(file.read())) };

	do {
		GameUI::DisplayLevelsMessage(bestResults);


		const Game::Level level{ GameUI::GetSelectedLevel() };

		GameUI::DisplayStartingGameMessage(level);
	
		auto result{ Game::Play(level) };

		bestResults.push_back(result);
		GameUI::DisplayResultMessege(result);

	} while (GameUI::ShouldContinue());

	file.write(ResultJsonConverter::Serialize(Game::FindBestResults(bestResults)));

	return 0;
}