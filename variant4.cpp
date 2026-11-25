#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Функция для проверки IP-адреса
bool isValidIP(const std::string& ip) {
    std::stringstream ss(ip);
    std::string segment;
    std::vector<std::string> segments;

    while (std::getline(ss, segment, '.')) {
        segments.push_back(segment);
    }

    if (segments.size() != 4) return false;

    for (const auto& seg : segments) {
        if (seg.empty() || seg.length() > 3) return false;
        
        for (char c : seg) {
            if (!std::isdigit(c)) return false;
        }

        int num = std::stoi(seg);
        if (num < 0 || num > 255) return false;

        if (seg.length() > 1 && seg[0] == '0') return false;
    }
    return true;
}

int main() {
    std::cout << "IP Validator initialized.\n";
    return 0;
}