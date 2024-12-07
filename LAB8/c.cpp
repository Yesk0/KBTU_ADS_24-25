#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    int n;
    std::cin >> s >> n;
    std::vector<std::string> tapes(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> tapes[i];
    }

    int m = s.size();
    std::vector<int> covered(m + 1, 0); // массив для хранения покрытия

    for (const auto& tape : tapes) {
        int t_len = tape.size();
        for (size_t i = 0; i + t_len <= m; ++i) {
            bool match = true;
            for (int j = 0; j < t_len; ++j) {
                if (s[i + j] != tape[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                covered[i]++;
                covered[i + t_len]--;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        count += covered[i];
        if (count <= 0) {
            std::cout << "NO";
            return 0;
        }
    }

    std::cout << "YES";
    return 0;
}