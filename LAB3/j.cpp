#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Функция для проверки, можно ли украсть все слитки с заданной скоростью K за H часов
bool canStealAll(const vector<int>& bags, int K, int H) {
    int hours_needed = 0;
    for (int gold : bags) {
        // Для каждого мешка считаем, сколько часов понадобится для кражи всех слитков из этого мешка
        hours_needed += (gold + K - 1) / K; // эквивалентно округлению вверх
        if (hours_needed > H) {
            return false;
        }
    }
    return hours_needed <= H;
}

int main() {
    int N, H;
    cin >> N >> H;
    
    vector<int> bags(N);
    for (int i = 0; i < N; ++i) {
        cin >> bags[i];
    }
    
    // Бинарный поиск по значению K
    int left = 1, right = *max_element(bags.begin(), bags.end());
    int result = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canStealAll(bags, mid, H)) {
            result = mid; // если можно украсть все с текущей K, сохраняем результат
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << result << endl;
    
    return 0;
}