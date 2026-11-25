#include <iostream>
#include <string>
#include <sstream>

// Функция подсчета слов
int countWords(const std::string& text) {
    std::istringstream iss(text);
    std::string word;
    int count = 0;
    while (iss >> word) {
        ++count;
    }
    return count;
}

int main() {
    std::cout << "Program for variant 4 started.\n";
    return 0;
}