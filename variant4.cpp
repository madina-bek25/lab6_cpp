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
    std::vector<std::string> testIPs = {
        "192.168.1.1",
        "255.255.255.255",
        "256.100.50.25",
        "192.168.1",
        "192.168.01.1",
        "abc.def.ghi.jkl"
    };

    std::cout << "--- Testing IP addresses ---\n";
    for (const auto& ip : testIPs) {
        std::cout << ip << " -> " 
                  << (isValidIP(ip) ? "Valid" : "Invalid") << "\n";
    }
    return 0;
}