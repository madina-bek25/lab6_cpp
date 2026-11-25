#include <iostream>
#include <string>
#include <cctype>

// Функция для извлечения чисел и подсчета их суммы
int sumNumbersInText(const std::string& text) {
    int sum = 0;
    std::string currentNumber = "";

    for (char c : text) {
        if (std::isdigit(c)) {
            currentNumber += c; 
        } else if (!currentNumber.empty()) {
            sum += std::stoi(currentNumber); 
            currentNumber = ""; 
        }
    }
    if (!currentNumber.empty()) {
        sum += std::stoi(currentNumber);
    }

    return sum;
}

int main() {
    std::cout << "Number extractor initialized.\n";
    return 0;

    
}