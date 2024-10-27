#include <bits/stdc++.h> 
using namespace std; 
 
 
void merge(vector<int>& arr, int left, int right, int mid) { 
    int n1 = mid - left + 1; 
    int n2 = right - mid; 
    vector<int> L(n1), R(n2); 
 
    for (int i = 0; i < n1; i++) { 
        L[i] = arr[left + i]; 
    } 
    for (int j = 0; j < n2; j++) { 
        R[j] = arr[mid + 1 + j]; 
    } 
 
    int i = 0, j = 0; 
    int k = left; 
 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
 
 
void mergesort(vector<int>& array, int left, int right) { 
    if (left >= right) { 
        return; 
    } 
    int mid = left + (right - left) / 2; 
    mergesort(array, left, mid); 
    mergesort(array, mid + 1, right); 
    merge(array, left, right, mid); 
} 
 
int main() { 
     
    int n, m; 
    cin >> n >> m; 
 
    vector<int> sandar(n), sandar1(m); 
 
    for (int i = 0; i < n; i++) { 
        cin >> sandar[i]; 
    } 
 
    
    for (int i = 0; i < m; i++) { 
        cin >> sandar1[i]; 
    } 
 
    if (n > 0) mergesort(sandar, 0, n - 1); 
    if (m > 0) mergesort(sandar1, 0, m - 1); 
 
    int i = 0, j = 0; 
    vector<int> common; 
    while (i < n && j < m) { 
        if (sandar[i] == sandar1[j]) { 
            common.push_back(sandar[i]); 
            i++; 
            j++; 
        } else if (sandar[i] < sandar1[j]) { 
            i++; 
        } else { 
            j++; 
        } 
    } 
 
    if (!common.empty()) { 
        for (int k = 0; k < common.size(); k++) { 
            if (k > 0) cout << " ";  
            cout << common[k]; 
        } 
    }
}