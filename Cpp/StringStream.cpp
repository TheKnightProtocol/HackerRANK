#include <sstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<int> parseInts(std::string str) {
    std::vector<int> result;
    std::stringstream ss(str);
    int num;
    char ch;
    
    // Read first number
    if (ss >> num) {
        result.push_back(num);
    }
    
    // Read remaining numbers with comma separator
    while (ss >> ch >> num) {
        result.push_back(num);
    }
    
    return result;
}

int main() {
    std::string str;
    std::cin >> str;
    std::vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        std::cout << integers[i] << "\n";
    }
    
    return 0;
}
