#pragma once

#ifndef _14_54_27_10_2024_GAME_H_
#define _14_54_27_10_2024_GAME_H_

#include "Result.h"
#include "Level.h"

namespace Game {
	/// <summary>
	/// Plays a number guessing game, allowing the player to guess a random number
	/// within a specific range based on the provided difficulty level.
	/// </summary>
	/// <param name="level">The difficulty level of the game, which determines the number of guesses
	/// the player has.</param>
	/// <returns>
	/// A Result object containing the number of chances used by the player 
	/// (or -1 if they did not guess correctly) and the time it took them to guess 
	/// (in seconds).
	/// </returns>///
	Result Play(const Level& level);
}

#endif // !_14_54_27_10_2024_GAME_H_