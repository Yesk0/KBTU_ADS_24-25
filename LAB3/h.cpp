#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int upperBound(const vector<int>& arr, int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    cin >> arr[0];
    
    // Считываем и одновременно строим префиксную сумму
    for (int i = 1; i < n; i++) {
        int temp;
        cin >> temp;
        arr[i] = arr[i - 1] + temp;
    }

    // Для каждого запроса ищем результат через upper_bound
    for (int i = 0; i < q; i++) {
        int key;
        cin >> key;
        cout << upperBound(arr, n, key) + 1 << endl;
    }

    return 0;
}