#pragma once

class Gluing {
public:
	void CallFunction();
private:
	int Num(const std::string& extracred_string, size_t& extracted_position);
	int Calculate(const std::string& received_string, size_t& starting_position);
};
