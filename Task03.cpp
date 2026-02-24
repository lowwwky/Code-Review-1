//К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить сколько 
//имеется чисел из N(1 < N < 20, K + N < 26) разрядов таких, что в их записи не содержится 
//два и более подряд идущих нулей.Для того, чтобы избежать переполнения, ответ
//представьте в виде вещественного числа.

#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <locale.h>

// FIX_ME: В Google C++ Style запрещается использовать namespcae std; 
//using namespace std;

std::vector<int> EnterDigits() {
    int numeric_system = 0;
    int amount_of_digits = 0;
    while (true) {
        while (true) {
            std::cout << "Введите систему счисления(целое число 2 <= CC <= 10): ";
            if (!(std::cin >> numeric_system)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (numeric_system >= 2 && numeric_system <= 10) {
                break;
            }
        }
        while (true) {
            std::cout << "Введите количество разрядов(целое число 1 < N < 20): ";
            if (!(std::cin >> amount_of_digits)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (amount_of_digits >= 2 && amount_of_digits <= 19) {
                break;
            }

        }
        if ((numeric_system + amount_of_digits > 0) && (numeric_system + amount_of_digits < 26)) {
            break;
        }
    }

    return std::vector<int>{numeric_system, amount_of_digits};
}

double Сalculate(int numeric_system, int amount_of_digits) {
    std::vector<std::vector<double>> dp(amount_of_digits + 1, std::vector<double>(numeric_system, 0));

    for (int j = 0; j < numeric_system; ++j) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= amount_of_digits; ++i) {
        for (int j = 1; j < numeric_system; ++j) {
            dp[i][0] += dp[i - 1][j];
        }

        for (int j = 1; j < numeric_system; ++j) {
            for (int l = 0; l < numeric_system; ++l) {
                dp[i][j] += dp[i - 1][l];
            }
        }
    }

    double result = 0;
    for (int j = 1; j < numeric_system; ++j) {
        result += dp[amount_of_digits][j];
    }

    return result;
}

int main() {
    //setlocale(LC_ALL, "ru");
    setlocale(LC_ALL, "Russian");

    // FIX_ME: Отдельные задачи лучше разбивать на несколько методов.
    // FIX_ME: Отсутсвуют какие-либо проверки на корректность вводимых данных.
    // FIX_ME: Отсуствует дружелюбный пользовательский интерфейс. 
    //int K, N;
    //cout << "Введите K и N: ";
    //cin >> K >> N;
    //std::cout << "Введите К и N: ";
    //std::cin >> K >> N;

    //vector<vector<double>> dp(N + 1, vector<double>(K, 0));
    //std::vector<std::vector<double>> dp(N + 1, std::vector<double>(K, 0));

    //for (int j = 0; j < K; ++j) {
    //    dp[1][j] = 1;
    //}

    //for (int i = 2; i <= N; ++i) {
    //    for (int j = 1; j < K; ++j) {
    //        dp[i][0] += dp[i - 1][j];
    //    }

    //    for (int j = 1; j < K; ++j) {
    //        for (int l = 0; l < K; ++l) {
    //            dp[i][j] += dp[i - 1][l];
    //        }
    //    }
    //}

    std::vector<int> digits = EnterDigits();
    for (int i = 0; i < digits.size(); i++) {
        std::cout << digits[i] << " ";
    }
    std::cout << std::endl;
    int numeric_system = digits[0];
    int amount_of_digits = digits[1];

    //double result = 0;
    //for (int j = 1; j < K; ++j) {
    //    result += dp[N][j];
    //}
    //cout << "Ответ: " << result << endl;
    //std::cout << "Ответ: " << result << std::endl;

    double result = Сalculate(numeric_system, amount_of_digits);
    std::cout << "Ответ: " << result << std::endl;

    return 0;

}
