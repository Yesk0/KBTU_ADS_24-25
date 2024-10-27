#include <bits/stdc++.h> 
using namespace std; 
 
 
bool sum_compare(const vector<int>& a, const vector<int>& b) { 
    int sum_a = accumulate(a.begin(), a.end(), 0);   
    int sum_b = accumulate(b.begin(), b.end(), 0);   
 
    if (sum_a != sum_b) { 
        return sum_a > sum_b;   
    } else { 
        return a < b;   
    } 
} 
 
int main() { 
    int n, m; 
    cin >> n >> m; 
 
     
    vector<vector<int>> vec(n, vector<int>(m)); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            cin >> vec[i][j]; 
        } 
    } 
 
    
    sort(vec.begin(), vec.end(), sum_compare); 
 
    
    for (const auto& row : vec) { 
        for (int i = 0; i < m; i++) { 
            cout << row[i] << " "; 
        } 
        cout << "\n"; 
    } 
 
 
}