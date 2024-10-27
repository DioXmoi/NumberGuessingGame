#pragma once


#ifndef _14_46_27_10_2024_RANDOM_H_
#define _14_46_27_10_2024_RANDOM_H_


#include <random>
#include <chrono>


namespace Random {

	inline std::mt19937 Generate() {
		std::random_device rd{ };

		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	inline std::mt19937 mt{ Generate() };

	inline int Get(int min, int max) {
		return std::uniform_int_distribution{ min, max }(mt);
	}
}

#endif // !_14_46_27_10_2024_RANDOM_H_
