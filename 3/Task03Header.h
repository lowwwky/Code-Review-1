#pragma once

# include <vector>

class Counter {
public:
	void CallFunction();
private: 
	std::vector<int> EnterDigits();
	double Сalculate(int numeric_system, int amount_of_digits);
};