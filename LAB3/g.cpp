#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const vector<int>& arr, long long f, int capacity) {
    int count = 0;
    for (int i : arr) {
        count += i / capacity;
        if (i % capacity > 0) count++;
    }
    return count <= f;
}

int BinarySearchCapacity(const vector<int>& arr, int n, long long f) {
    int low = 1;
    int high = arr[n - 1];

    int res = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(arr, f, mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return res;
}

int main() {
    int n;
    long long f;

    cin >> n >> f;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Сортировка массива
    sort(arr.begin(), arr.end());

    // Вызов бинарного поиска для поиска минимальной емкости
    cout << BinarySearchCapacity(arr, n, f) << endl;

    return 0;
}