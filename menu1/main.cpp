#include <iostream>
#include <string>
#include <algorithm>
#include <random>

void reverse(const std::string& word) { //переворачивает слово задом наперед
    std::string reversedWord = word;
    std::reverse(reversedWord.begin(), reversedWord.end());
    std::cout << "Результат: " << reversedWord << std::endl;
}

void removeVowels(const std::string& word) { //удаляет гласные буквы в слове
    std::string vowels = "aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ";
    std::string result = "";
    for (char letter : word) {
        if (vowels.find(letter) == std::string::npos) {
            result += letter;
        }
    }
    std::cout << "Результат: " << result << std::endl;
}

void removeConsonants(const std::string& word) { //удаляет согласные буквы из слов
    std::string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZбвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
    std::string result = "";
    for (char letter : word) {
        if (consonants.find(letter) == std::string::npos) {
            result += letter;
        }
    }
    std::cout << "Результат: " << result << std::endl;
}

void shuffle(const std::string& word) {
    std::string shuffledWord = word;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(shuffledWord.begin(), shuffledWord.end(), generator); // перемешивает буквы в слове
    std::cout << "Результат: " << shuffledWord << std::endl;
}

void menu() {
    std::cout << "Меню:" << std::endl;
    std::cout << "1. Слово выводится задом наперед." << std::endl;
    std::cout << "2. Вывести слово без гласных." << std::endl;
    std::cout << "3. Вывести слово без согласных." << std::endl;
    std::cout << "4. Рандомно раскидывать буквы заданного слова." << std::endl;

    int choice;
    std::cout << "Выберите действие (1-4): ";
    std::cin >> choice;

    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;

    switch (choice) {
        case 1:
            reverse(word);
            break;
        case 2:
            removeVowels(word);
            break;
        case 3:
            removeConsonants(word);
            break;
        case 4:
            shuffle(word);
            break;
        default:
            std::cout << "Ошибка: неверный выбор действия." << std::endl;
            break;
    }
}

int main() {
    menu();
    return 0;
}


