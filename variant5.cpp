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
    std::string testText = "В 2023 году я купил 3 яблока за 150 рублей, а потом продал за 200.";
    
    std::cout << "Текст: " << testText << "\n";
    std::cout << "Сумма всех чисел в тексте: " << sumNumbersInText(testText) << "\n";
    
    return 0;
}