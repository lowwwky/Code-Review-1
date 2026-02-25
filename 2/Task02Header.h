#pragma once

# include <vector>


class Artifacts {
public:
	void CallFunction();
private: 
	void readArtifacts(int& amount_of_artifact, int& weight_to_overcome, std::vector<int>& weights, std::vector<int>& taxes);
	void findMinBurden(int amount_of_artifacts, int weight_to_top, int& best_weight, int& min_tax,
		std::vector<int>& weights, std::vector<int>& taxes, std::vector<bool>& best_selection);
};