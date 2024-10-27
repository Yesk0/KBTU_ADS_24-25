#include <iostream>
#include <vector>

using namespace std;

void mergeArrays(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    int m = b.size();
    vector<int> merged;
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            merged.push_back(a[i]);
            i++;
        } else {
            merged.push_back(b[j]);
            j++;
        }
    }
    
    while (i < n) {
        merged.push_back(a[i]);
        i++;
    }
    
    while (j < m) {
        merged.push_back(b[j]);
        j++;
    }
    
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    mergeArrays(a, b);
    
    return 0;
}