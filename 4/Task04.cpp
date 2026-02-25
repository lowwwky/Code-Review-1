//Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения, 
//не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
//Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
//определяется следующим образом(функция M возвращает максимальный из своих параметров,
//а функция m — минимальный) :
//	<выражение> :: = <цифра> | M(<выражение>, <выражение>) | m(<выражение>, <выражение>)

# include <iostream>
# include <string>
# include <algorithm>
//# include <Windows.h>
# include "Task04Header.h"

// FIX_ME: В Google C++ Style запрещается использовать namespace std; 
//using namespace std;

// FIX_ME: В google c++ codestyle названия методов пишутся с заглавной буквы.
// FIX_ME: В google c++ codestyle форматирование скобок идет рядом с if/while...
// FIX_ME: Именование должно быть информативным.
//int num(const string& s, size_t& pos)
int Gluing::Num(const std::string& extracred_string, size_t& extracted_position) {
	//{
	int number = 0;
	//while (pos < s.length() && s[pos] >= '0' && s[pos] <= '9') {
		//number = number * 10 + (s[pos] - '0');
		//pos++;
	while (extracted_position < extracred_string.length() && extracred_string[extracted_position] >= '0' && extracred_string[extracted_position] <= '9') {
		number = number * 10 + (extracred_string[extracted_position] - '0');
		extracted_position++;
	}
	return number;
}

// FIX_ME: В google c++ codestyle названия методов пишутся с заглавной буквы.
// FIX_ME: В google c++ codestyle форматирование скобок идет рядом с if/while...
// FIX_ME: Именование должно быть информативным.
//int calc(const string &s,size_t& pos)
//{
int Gluing::Calculate(const std::string& received_string, size_t& starting_position) {
	if (received_string[starting_position] >= '0' && received_string[starting_position] <= '9') {
		//return num(s, pos);
		return Num(received_string, starting_position);
	}

	if (received_string[starting_position] == 'M' || received_string[starting_position] == 'm') {
		//{
			// FIX_ME: Именование должно быть информативным.
		char operation = received_string[starting_position];
		starting_position++;

		//пропускаю (
		while (starting_position < received_string.length() && received_string[starting_position] != '(') {
			//{
			starting_position++;
		}
		starting_position++;

		//int left = calc(s, pos);
		int left = Calculate(received_string, starting_position);

		// пропускаю ,
		while (starting_position < received_string.length() && received_string[starting_position] != ',') {
			//{
			starting_position++;
		}
		starting_position++;

		// int right = calc(s, pos);
		int right = Calculate(received_string, starting_position);

		// пропускаю )
		while (starting_position < received_string.length() && received_string[starting_position] != ')') {
			// {
			starting_position++;
		}
		starting_position++;

		if (operation == 'M') {
			//{
				//return max(left, right);
			if (left > right)
				return left;
			else
				return right;
		}
		else {
			//{
				//return min(left, right);
			if (left < right)
				return left;
			else
				return right;
		}
	}

	if (received_string[starting_position] == '(') {
		starting_position++; // Пропускаем '('
		//int result = calc(s, pos); // продолжаем вычислять уже внутреннее выражение
		int result = Calculate(received_string, starting_position);
		if (received_string[starting_position] != ')') {
			//cout << "Ожидается закрывающая скобка";
			std::cout << "Ожидается закрывающая скобка. ";
		}
		starting_position++; // Пропускаем ')'
		return result;
	}
}

void Gluing::CallFunction() {
//int main() {
//{
	// FIX_ME: Использование SetConsoleCP и SetConsoleOutputCP делает программу менее переносимой.
	// SetConsoleCP(1251);
	// SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	// FIX_ME: Слишком расплывчатое описание задачи.
	//cout << "Добро пожаловать! " << endl;
	//cout << "Перед нами стоит задача: найти значение выражения типа" << endl;
	//cout << " <выражение> ::= <цифра> | M(<выражение> , <выражение>) | "<< endl;
	//cout << "m(<выражение>, <выражение>)" << endl;
	//cout << "где M - функция, которая выбирает большее значение из двух чисел." << endl;
	//cout << "а m - функция, которая выбирает меньшее значение из двух чисел." << endl;
	//cout << "-------------------------------------------------" << endl;
	//cout << endl;
	//cout << endl;
	//cout << "Ваша задача - записать любое выражение, которое вы захотите" << endl;
	//cout << "БЕЗ ИСПОЛЬЗОВАНИЯ ПРОБЕЛОВ" << endl;
	//cout << "А мы посчитаем значение и выведем его на экран." << endl;
	//cout << "Важное замечание: вводить можно только целые неотрицательные числа." << endl;
	//cout << "-------------------------------------------------" << endl;
	//cout << endl;
	//cout << endl;
	//cout << "Выражение может выглядеть так:" << endl;
	//cout << "M(1234,m(12345,M(175,m(1270,1980))))" << endl;
	//cout << "m(M(12759,m(1370,140)),m(1345,6789))" << endl;
	//cout << endl;
	//cout << endl;

	std::cout << "Задача: найти значение выражения типа" << std::endl
		<< "<выражение> ::= <цифра> | M(<выражение> , <выражение>) | " << std::endl
		<< "m(<выражение>, <выражение>)" << std::endl
		<< "M - функция, которая выбирает БОЛЬШЕЕ значение из двух чисел." << std::endl
		<< "m - функция, которая выбирает МЕНЬШЕЕ значение из двух чисел." << std::endl << std::endl;

	std::cout << "Важное замечание: вводить можно только целые неотрицательные числа." << std::endl << std::endl;

	std::cout << "Выражение может выглядеть так: " << std::endl
		<< "M(1234,m(12345,M(175,m(1270,1980))))" << std::endl
		<< "m(M(12759,m(1370,140)),m(1345,6789))" << std::endl
		<< std::endl;

	// FIX_ME: Именование должно быть информативным.
	//string s;
	//cout << "Введите выражение:";
	//getline(cin, s);
	//int result = calc(s, pos);
	std::string input_string;
	std::cout << "Введите выражение: ";
	getline(std::cin, input_string);
	size_t position = 0;

	int result = Calculate(input_string, position);

	//cout << endl;
	//cout << "Полученный результат равен: ";
	//cout << result << " ";

	std::cout << std::endl;
	std::cout << "Полученный результат равен: ";
	std::cout << result << " ";

	//return 0;
}
