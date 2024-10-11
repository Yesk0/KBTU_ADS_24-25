#include <bits/stdc++.h> 
using namespace std; 
 
struct Node { 
    int key; 
    Node* left; 
    Node* right; 
    Node(int item) { 
        key = item; 
        left = right = nullptr; 
    } 
}; 
 
 
Node* insert(Node* root, int key) { 
    if (root == nullptr) { 
        return new Node(key);   
    } 
    if (key < root->key) { 
        root->left = insert(root->left, key);   
    } 
    else if (key > root->key) { 
        root->right = insert(root->right, key);   
    } 
    return root; 
} 
 
 
void Print(Node* root, int level, vector<int>& sum) { 
    if (root == nullptr) { 
        return; 
    } 
    if (level >= sum.size()) { 
        sum.push_back(0);   
    } 
    sum[level] += root->key;   
 
    
    Print(root->left, level + 1, sum); 
    Print(root->right, level + 1, sum); 
} 
 
int main() { 
    Node* root = nullptr; 
    int n; 
    cin >> n; 
    vector<int> sandar(n); 
 
    for (int i = 0; i < n; i++) { 
        cin >> sandar[i]; 
        root = insert(root, sandar[i]); 
    } 
int level=0; 
   
    vector<int> sum; 
    Print(root, level, sum);   
 
   cout<<sum.size()<<"\n"; 
    for (int element : sum) { 
        cout << element << " "; 
    } 
 
    return 0; 
}