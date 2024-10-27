#include "Level.h"
#include "Game.h"
#include "GameUI.h"


int main() {
	GameUI::DisplayWelcomeMessage();
	GameUI::DisplayLevelsMessage();

	const Level level{ GameUI::GetSelectedLevel() };

	GameUI::DisplayStartingGameMessage(level);
	
	GameUI::DisplayResultMessege(Game::Play(level));

	return 0;
}