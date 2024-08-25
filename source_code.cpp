#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <vector>
#include <algorithm>

const std::string letters = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяabcdefghijklmnopqrstuvwxyz";

std::string to_lowercase(const std::string& str) {
    std::string lower_str;
    std::locale loc;
    for (char c : str) {
        lower_str += std::tolower(c, loc);
    }
    return lower_str;
}

int babylon_shelf(const std::string& goal_word) {
    int counter = 0;
    std::string idk;
    std::srand(static_cast<unsigned>(std::time(0)));
    
    while (true) {
        idk.clear();
        for (size_t i = 0; i < goal_word.length(); ++i) {
            idk += letters[std::rand() % letters.size()];
        }
        counter++;
        /*if (counter % 1000000 == 0) {
            std::cout << "1,000,000 символов было перебраною" << std::endl;
        }*/
        if (to_lowercase(idk) == to_lowercase(goal_word)) {
            return counter;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Добро пожаловать в одну из полок Вавилонской Библиотеки! Здесь можно найти любое слово, но чем оно длинее, тем больше времени понадобится - одно слово можно искать тысячи лет(!)" << std::endl;

    std::string goal_word;
    std::cout << "Какое слово вы хотите найти? ";
    std::getline(std::cin, goal_word);

    // Запоминаем текущее время до выполнения функции
    clock_t start_time = clock();

    int attempts = babylon_shelf(goal_word);

    // Запоминаем текущее время после выполнения функции
    clock_t end_time = clock();

    double execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    std::cout << "Слово " << goal_word << " было найдено! Для этого понадобилось перебрать " << attempts << " символов, это заняло " << execution_time << " секунд." << std::endl;

    return 0;
}
