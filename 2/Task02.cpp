//Археолог нашел N артефактов.Известны веса(сi) и налоговое бремя(di) находок.
//Нужно выбрать такое подмножество находок, чтобы их суммарный вес превысил Z кг, а их об
//щее налоговое бремя оказалось минимальным.Известно, что решение единственно.Укажите
//порядковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом фай
//ле, в первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - величина
//налога по каждой находке.Вывести так же суммарный вес и общую ценность результата.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Task02Header.h"
// #include <Windows.h>

// FIX_ME: В Google C++ Style запрещается использовать namespace std; 
//using namespace std;

void Artifacts::readArtifacts(int& amount_of_artifact, int& weight_to_overcome, std::vector<int>& weights, std::vector<int>& taxes) {
    // FIX_ME: В задании не написано, что выходные данные должны быть выведены в текстовый файл.
    // FIX_ME: Отсутсвует проверка на созданный файл.
    //ifstream input("input.txt");
    //ofstream output("output.txt");
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        //cout << "Ошибка при открытии файла" << endl;
        std::cout << "Ошибка при открытии файла " << std::endl;
        std::exit(1);
    }

    // Именование должно быть информативным.
    //input >> N >> Z;
    input >> amount_of_artifact >> weight_to_overcome;

    weights.resize(amount_of_artifact);
    taxes.resize(amount_of_artifact);

    //for (int i = 0; i < N; ++i) { //цикл для чтения весов и налогов из файла
    for (int i = 0; i < amount_of_artifact; ++i) {
        input >> weights[i];
    }

    //for (int i = 0; i < N; ++i) {
    for (int i = 0; i < amount_of_artifact; ++i) {
        input >> taxes[i];
    }

    input.close();
}

void Artifacts::findMinBurden(int amount_of_artifacts, int weight_to_top, int& best_weight, int& min_tax,
    std::vector<int>& weights, std::vector<int>& taxes, std::vector<bool>& best_selection) {
    // Инициализация массива для хранения минимального налогового бремени для каждого возможного веса
   //int max_possible_weight = Z + 100; // Максимально возможный вес
    int max_possible_weight = weight_to_top + 100;
    //vector<int> dp(max_possible_weight + 1, INT_MAX);//Создает вектор dp, где dp[j] хранит минимальное налоговое бремя для веса j. Изначально все значения равны INT_MAX
    std::vector<int> dp(max_possible_weight + 1, INT_MAX);
    dp[0] = 0;

    // Массив для хранения выбранных артефактов
    //Создает двумерный вектор selected, где selected[j][i] указывает, выбран ли i-й артефакт для веса j
    //vector<vector<bool>> selected(max_possible_weight + 1, vector<bool>(N, false));
    std::vector<std::vector<bool>> selected(max_possible_weight + 1, std::vector<bool>(amount_of_artifacts, false));
    //for (int i = 0; i < N; ++i) { // перебирает все артефакты
    for (int i = 0; i < amount_of_artifacts; ++i) {
        for (int j = max_possible_weight; j >= weights[i]; --j) { //перебирает все возмож веса
            if (dp[j - weights[i]] != INT_MAX && dp[j - weights[i]] + taxes[i] < dp[j]) {
                dp[j] = dp[j - weights[i]] + taxes[i]; //обновляет мин нал бремя для веса J
                selected[j] = selected[j - weights[i]]; // Копирует выбранные артефакты для веса j - weights[i].
                selected[j][i] = true;
            }
        }
    }

    //for (int j = Z + 1; j <= max_possible_weight; ++j) { //перебирает все веса > Z
    for (int j = weight_to_top + 1; j <= max_possible_weight; ++j) {
        if (dp[j] < min_tax) {
            min_tax = dp[j];
            best_weight = j;
            best_selection = selected[j];
        }
    }

}
 
void Artifacts::CallFunction() {
//int main() {
    // FIX_ME: Использование SetConsoleCP и SetConsoleOutputCP делает программу менее переносимой.
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    //setlocale(LC_ALL, "ru");

    // FIX_ME: Отдельные задачи лучше разбивать на несколько методов.
    // Это повышает читаемость, упрощает тестирование и делает программу более маштабируемой.

    //ifstream input("input.txt");
    //ofstream output("output.txt");
    //std::ifstream input("input.txt");
    // FIX_ME: В задании не написано, что выходные данные должны быть выведены в текстовый файл.
    //std::ofstream output("output.txt");

    // Именование должно быть информативным.
    //int N, Z;// кол во артеф и мин треб вес
    //input >> N >> Z;

    //vector<int> weights(N);//вектор для хранения весов артф
    //vector<int> taxes(N);//вектор для хранения налового бремени

    //for (int i = 0; i < N; ++i) { //цикл для чтения весов и налогов из файла
    //for (int i = 0; i < amount_of_artifacts; ++i) {
    //    input >> weights[i];
    //}

    //for (int i = 0; i < N; ++i) {
    //for (int i = 0; i < amount_of_artifacts; ++i) {
    //    input >> taxes[i];
    //}

    // Инициализация массива для хранения минимального налогового бремени для каждого возможного веса
    //int max_possible_weight = Z + 100; // Максимально возможный вес
    //int max_possible_weight = weight_to_exceed + 100;
    //vector<int> dp(max_possible_weight + 1, INT_MAX);//Создает вектор dp, где dp[j] хранит минимальное налоговое бремя для веса j. Изначально все значения равны INT_MAX
    //std::vector<int> dp(max_possible_weight + 1, INT_MAX);
    //dp[0] = 0;

    // Массив для хранения выбранных артефактов
    //Создает двумерный вектор selected, где selected[j][i] указывает, выбран ли i-й артефакт для веса j
    //vector<vector<bool>> selected(max_possible_weight + 1, vector<bool>(N, false));
    //std::vector<std::vector<bool>> selected(max_possible_weight + 1, std::vector<bool>(amount_of_artifacts, false));
    //for (int i = 0; i < N; ++i) { // перебирает все артефакты
    //for (int i = 0; i < amount_of_artifacts; ++i) {
    //    for (int j = max_possible_weight; j >= weights[i]; --j) { //перебирает все возмож веса
    //        if (dp[j - weights[i]] != INT_MAX && dp[j - weights[i]] + taxes[i] < dp[j]) {
    //            dp[j] = dp[j - weights[i]] + taxes[i]; //обновляет мин нал бремя для веса J
    //            selected[j] = selected[j - weights[i]]; // Копирует выбранные артефакты для веса j - weights[i].
    //            selected[j][i] = true;
    //        }
    //    }
    //}

    // Находим минимальное налоговое бремя для веса, превышающего Z
    //int min_tax = INT_MAX;
    //int best_weight = 0;
    //vector<bool> best_selection;
    //std::vector<bool> best_selection;

    //for (int j = Z + 1; j <= max_possible_weight; ++j) { //перебирает все веса > Z
    //for (int j = weight_to_exceed + 1; j <= max_possible_weight; ++j) {
    //    if (dp[j] < min_tax) {
    //        min_tax = dp[j];
    //       best_weight = j;
    //        best_selection = selected[j];
    //    }
    //}

    int min_tax = INT_MAX;
    int best_weight = 0;
    int amount_of_artifacts = 0, weight_to_exceed = 0;
    std::vector<int> weights;
    std::vector<int> taxes;
    std::vector<bool> best_selection;
    readArtifacts(amount_of_artifacts, weight_to_exceed, weights, taxes);
    findMinBurden(amount_of_artifacts, weight_to_exceed, best_weight, min_tax, weights, taxes,best_selection);

    // Выводим результат
    //output << "Выбранные артефакты: ";
    std::cout << "Выбранные артефакты: ";
    //for (int i = 0; i < N; ++i) {
    for (int i = 0; i < amount_of_artifacts; ++i) {
        if (best_selection[i]) {
            //output << i + 1 << " ";
            std::cout << i + 1 << " ";
        }
    }
    //output << endl;
    std::cout << std::endl;

    //output << "Суммарный вес: " << best_weight << " кг" << endl;
    //output << "Общее налоговое бремя: " << min_tax << endl;
    std::cout << "Суммарный вес: " << best_weight << " кг" << std::endl;
    std::cout << "Общее налоговое бремя: " << min_tax << std::endl;

    //input.close();
    //output.close();

    //return 0;
}


