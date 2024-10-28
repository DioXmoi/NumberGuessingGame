#include "Level.h"
#include "Game.h"
#include "GameUI.h"


int main() {
	GameUI::DisplayWelcomeMessage();

	do {
		GameUI::DisplayLevelsMessage();

		const Level level{ GameUI::GetSelectedLevel() };

		GameUI::DisplayStartingGameMessage(level);
	
		GameUI::DisplayResultMessege(Game::Play(level));

	} while (GameUI::ShouldContinue());
	
	//Добавьте таймер, чтобы видеть, сколько времени требуется пользователю, чтобы угадать число

	return 0;
}