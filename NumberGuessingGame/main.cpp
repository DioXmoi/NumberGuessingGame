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
	

	return 0;
}

//Разрешите пользователю сыграть несколько раундов(т.е.продолжайте играть до тех пор, 
//пока пользователь не решит выйти).
//Вы можете сделать это, 
//спрашивая пользователя, 
//хочет ли он продолжить игру после каждого раунда.