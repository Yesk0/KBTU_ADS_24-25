#include <iostream>
#include <string>
#include <vector>

// Функция для построения префикс-функции для строки
std::vector<int> computeKMPTable(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> kmp(m);
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = kmp[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        kmp[i] = j;
    }
    return kmp;
}

// Функция для поиска подстроки с использованием KMP
std::vector<int> KMP(const std::string& text, const std::string& pattern) {
    std::vector<int> result;
    std::vector<int> kmp = computeKMPTable(pattern);
    int n = text.size(), m = pattern.size();
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = kmp[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            result.push_back(i - m + 1);
            j = kmp[j - 1];
        }
    }
    return result;
}

int main() {
    std::string s1, s2, t;
    std::cin >> s1 >> s2 >> t;

    // Найти все вхождения `t` в `s1` и `s2`
    std::vector<int> positions1 = KMP(s1, t);
    std::vector<int> positions2 = KMP(s2, t);

    // Подсчитать количество совпадающих позиций
    int count = 0;
    size_t i = 0, j = 0;
    while (i < positions1.size() && j < positions2.size()) {
        if (positions1[i] == positions2[j]) {
            ++count;
            ++i;
            ++j;
        } else if (positions1[i] < positions2[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    std::cout << count << std::endl;
    return 0;
}