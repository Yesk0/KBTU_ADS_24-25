#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void buildBalancedBST(vector<int> &arr, vector<int> &result, int left, int right) {
    if (left > right) return;
    
    int mid = (left + right) / 2;
    result.push_back(arr[mid]);
    
    // Recursively build left and right subtrees
    buildBalancedBST(arr, result, left, mid - 1);
    buildBalancedBST(arr, result, mid + 1, right);
}

int main() {
    int N;
    cin >> N;

    int size = (1 << N) - 1;  // 2^N - 1
    vector<int> arr(size);
    
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Sort the array to create a valid BST
    sort(arr.begin(), arr.end());

    vector<int> result;
    buildBalancedBST(arr, result, 0, size - 1);
    
    // Output the result
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    return 0;
}