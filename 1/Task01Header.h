#pragma once

#include <vector>

// Класс, реализующий поставленную задачу.
class Artifacts {
public:	
	int CallFunction();
private: 
	void WriteArtifacts(int& amount_of_artifacts, int& weight_to_exceed, std::vector<int>& weights, std::vector<int>& burden);
	void SelectArts(std::vector<std::vector<int>>& min_taxes, int artifact_count, int total_weight,
		std::vector<int>& weights, std::vector<int>& burden, std::vector<int>& answer_sequence);
	void FindMinimalBurden(int amount_of_artifacts, int weight_to_exceed, int& total_weight, int& min_burden,
		std::vector<int>& weights, std::vector<int>& burden, std::vector<int> answer_sequence);
};

