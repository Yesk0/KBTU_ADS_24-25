#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) break;

        std::vector<std::string> patterns(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> patterns[i];
        }

        std::string text;
        std::cin >> text;

        std::unordered_map<std::string, int> frequency;
        int max_frequency = 0;

        
        for (const auto& pattern : patterns) {
            int count = 0;
            for (size_t pos = text.find(pattern); pos != std::string::npos; pos = text.find(pattern, pos + 1)) {
                count++;
            }
            frequency[pattern] = count;
            max_frequency = std::max(max_frequency, count);
        }

       
        std::vector<std::string> dominating_patterns;
        for (const auto& pattern : patterns) {
            if (frequency[pattern] == max_frequency) {
                dominating_patterns.push_back(pattern);
            }
        }

        std::cout << max_frequency << "\n";
        for (const auto& pattern : dominating_patterns) {
            std::cout << pattern << "\n";
        }
    }

    return 0;
}