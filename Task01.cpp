//Археолог нашел N артефактов.Известны веса(сi) и налоговое бремя(di) находок.
//Нужно выбрать такое подмножество находок, чтобы их суммарный вес превысил Z кг, а их общее 
//налоговое бремя оказалось минимальным.Известно, что решение единственно.Укажите
//порядковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом файле, 
//в первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - величина
//налога по каждой находке.Вывести так же суммарный вес и общую ценность результата.

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
//#include <Windows.h>

constexpr int kInf = INT_MAX / 4;

// FIX_ME: В Google C++ Style запрещается использовать namespace std; 
//using namespace std;

void WriteArtifacts(int& amount_of_artifacts, int& weight_to_exceed, std::vector<int>& weights, std::vector<int>& burden) {
    std::ifstream input("1.1.txt");
    if (!input.is_open()) {
        //cout << "Ошибка при открытии файла" << endl;
        std::cout << "Ошибка при открытии файла " << std::endl;
        std::exit(1);
    }
    input >> amount_of_artifacts >> weight_to_exceed;
    weights.resize(amount_of_artifacts + 1);
    burden.resize(amount_of_artifacts + 1);

    for (int i = 1; i <= amount_of_artifacts; i++) {
        input >> weights[i];
    }

    for (int i = 1; i <= amount_of_artifacts; i++) {
        input >> burden[i];
    }

    input.close();
}

// FIX_ME: Именование переменных должно быть информативным.
//void SelectArts(vector<vector<int>>& dp, int k, int s, vector<int>& weights, vector<int>& time) {
void SelectArts(std::vector<std::vector<int>>& min_taxes, int artifact_count, int total_weight,
    std::vector<int>& weights, std::vector<int>& burden, std::vector<int>& answer_sequence) {
    //if (k == 0 || s == 0)
    if (artifact_count == 0 || total_weight == 0)
        return;
    //if (dp[k][s] == dp[k - 1][s]) {
    if (min_taxes[artifact_count][total_weight] == min_taxes[artifact_count - 1][total_weight]) {
        //SelectArts(dp, k - 1, s, weights, time);
        SelectArts(min_taxes, artifact_count - 1, total_weight, weights, burden, answer_sequence);
    }
    else {
        // FIX_ME: Вывод данных лучше делать от начала до конца, а не наоборот.
        //cout << k << ' ';
        answer_sequence.push_back(artifact_count);
        //SelectArts(dp, k - 1, s - weights[k], weights, time);
        SelectArts(min_taxes, artifact_count - 1, total_weight - weights[artifact_count], weights, burden, answer_sequence);
    }

}

void FindMinimalBurden(int amount_of_artifacts, int weight_to_exceed, int& total_weight, int& min_burden,
    std::vector<int>& weights, std::vector<int>& burden, std::vector<int> answer_sequence) {
    int max_weight = 0;
    for (int w : weights) {
        max_weight += w;
    }

    // FIX_ME: Неочевидное название. 
    // FIX_ME: Невозможный вес(999) лучше представить в виде константы с бОльшим значением.
    //vector<vector<int>> dp(N + 1, vector<int>(max_weight + 1, 999));
    std::vector<std::vector<int>> min_tax(amount_of_artifacts + 1, std::vector<int>(max_weight + 1, kInf));
    for (int i = 0; i <= amount_of_artifacts; i++) {
        //dp[i][0] = 0;
        min_tax[i][0] = 0;
    }

    // FIX_ME: Неочевидное название.
    // for (int k = 1; k <= N; k++) {
    for (int item = 1; item <= amount_of_artifacts; item++) {
        // FIX_ME: Неочевидное название.
        // for (int s = 1; s <= max_weight; s++) {
        for (int weight = 1; weight <= max_weight; weight++) {
            // FIX_ME: Невозможный вес(999) лучше представить в виде константы с бОльшим значением.
            //if (s >= weights[k] && dp[k - 1][s - weights[k]] != 999) {
            if (weight >= weights[item] && min_tax[item - 1][weight - weights[item]] != kInf) {
                //dp[k][s] = min(dp[k - 1][s], dp[k - 1][s - weights[k]] + burden[k]);
                min_tax[item][weight] = std::min(min_tax[item - 1][weight], min_tax[item - 1][weight - weights[item]] + burden[item]);
            }
            else {
                //dp[k][s] = dp[k - 1][s];
                min_tax[item][weight] = min_tax[item - 1][weight];
            }
        }
    }

    // FIX_ME: Использование явного значения минимального может быть небезопасным для некоторых диапазонов значений.
    // FIX_ME: Перепутаны слова время и бремя.
    // int min_time = 9999;

    for (int s = weight_to_exceed + 1; s <= max_weight; s++) {
        // if (dp[N][s] < min_time) {
        if (min_tax[amount_of_artifacts][s] < min_burden) {
            //min_time = dp[N][s];
            min_burden = min_tax[amount_of_artifacts][s];
            total_weight = s;
        }
    }

    std::cout << "Выбранные артефакты -> ";
    SelectArts(min_tax, amount_of_artifacts, total_weight, weights, burden, answer_sequence);
    for (int i = answer_sequence.size() - 1; i >= 0; --i) {
        std::cout << answer_sequence[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // FIX_ME: Использование SetConsoleCP и SetConsoleOutputCP делает программу менее переносимой.
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    // FIX_ME: Лучше выносить отдельные задачи в отдельные методы для повышения читабельности кода.

    //ifstream input("1.1.txt");
    //std::ifstream input("1.1.txt");
    //if (!input.is_open()) {
    //    //cout << "Ошибка при открытии файла" << endl;
    //    std::cout << "Ошибка при открытии файла " << std::endl;
    //    return 1;
    //}

    // FIX_ME: Именование должно быть информативным.
    //int N, Z;
    //input >> N >> Z;

    //vector<int> weights(N + 1);
    // FIX_ME: Название перемменой должно быть бремя, а не время.
    //vector<int> time(N + 1);
    //std::vector<int> weights(N + 1);
    //std::vector<int> burden(N + 1);

    //for (int i = 1; i <= N; i++) {
    //    input >> weights[i];
    //}

    //for (int i = 1; i <= N; i++) {
    //    input >> burden[i];
    //}

    //input.close();

    //int max_weight = 0;
    //for (int w : weights) {
    //    max_weight += w;
    //}

    // FIX_ME: Неочевидное название.
    // FIX_ME: Невозможный вес(999) лучше представить в виде константы с бОльшим значением.
    //vector<vector<int>> dp(N + 1, vector<int>(max_weight + 1, 999));
    //std::vector<std::vector<int>> min_tax(N + 1, std::vector<int>(max_weight + 1, kInf));
    //for (int i = 0; i <= N; i++) {
        //dp[i][0] = 0;
    //    min_tax[i][0] = 0;
    //}

    // FIX_ME: Неочевидное название.
    // for (int k = 1; k <= N; k++) {
    //for (int item = 1; item <= N; item++) {
        // FIX_ME: Неочевидное название.
    //    for (int weight = 1; weight <= max_weight; weight++) {
            // FIX_ME: Невозможный вес(999) лучше представить в виде константы с бОльшим значением.
            //if (s >= weights[k] && dp[k - 1][s - weights[k]] != 999) {
    //        if (weight >= weights[item] && min_tax[item - 1][weight - weights[item] ] != kInf) {
                //dp[k][s] = min(dp[k - 1][s], dp[k - 1][s - weights[k]] + burden[k]);
    //            min_tax[item][weight] = min(min_tax[item - 1][weight], min_tax[item - 1][weight - weights[item]] + burden[item]);
    //        }
    //        else {
                //dp[k][s] = dp[k - 1][s];
    //           min_tax[item][weight] = min_tax[item - 1][weight];
    //        }
    //    }
    //}

    // FIX_ME: Использование явного значения минимального может быть небезопасным для некоторых диапазонов значений.
    // FIX_ME: Перепутаны слова время и бремя.
    // int min_time = 9999;
    //int min_burden = INT_MAX;
    //int total_weight = 0;

    //for (int s = Z + 1; s <= max_weight; s++) {
        // if (dp[N][s] < min_time) {
    //    if (min_tax[N][s] < min_burden) {
            //min_time = dp[N][s];
    //        min_burden = min_tax[N][s];
    //        total_weight = s;
    //    }
    //}

    int min_burden = INT_MAX;
    int total_weight = 0;
    int total_artifacts = 0;
    int weight_to_outgrow = 0;
    std::vector<int> weights;
    std::vector<int> taxes;
    std::vector<int> sequence;
    WriteArtifacts(total_artifacts, weight_to_outgrow, weights, taxes);
    FindMinimalBurden(total_artifacts, weight_to_outgrow, total_weight, min_burden, weights, taxes, sequence);

    //cout << "Выбранные артефакты -> ";
    //SelectArts(dp, N, total_weight, weights, burden);
    //cout << endl;

    //cout << "Суммарный вес -> " << total_weight << " кг" << endl;
    //cout << "Общее налоговое бремя -> " << min_time << endl;
    std::cout << "Суммарный вес -> " << total_weight << " кг" << std::endl;
    std::cout << "Общее налоговое бремя -> " << min_burden << std::endl;

    return 0;
}
