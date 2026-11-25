#include <iostream>
#include <string>
#include <cctype>

// Функция для извлечения чисел и подсчета их суммы
int sumNumbersInText(const std::string& text) {
    int sum = 0;
    std::string currentNumber = "";

    for (char c : text) {
        if (std::isdigit(c)) {
            currentNumber += c; // Собираем цифры в число
        } else if (!currentNumber.empty()) {
            sum += std::stoi(currentNumber); // Как только встретили не цифру - суммируем
            currentNumber = ""; // Сбрасываем буфер
        }
    }
    // Проверка на случай, если строка заканчивается цифрой
    if (!currentNumber.empty()) {
        sum += std::stoi(currentNumber);
    }

    return sum;
}

int main() {
    std::cout << "Number extractor initialized.\n";
    return 0;

    
}