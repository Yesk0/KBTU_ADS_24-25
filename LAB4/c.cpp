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
 
 
void Print(Node* root) { 
    if (root != nullptr) { 
        cout << root->key << " ";   
        Print(root->left);  
        Print(root->right);   
    } 
} 
 
 
Node* result(Node* root, int key) { 
    if (root == nullptr || root->key == key) { 
        return root;   
    } 
    if (key < root->key) { 
        return result(root->left, key);  
    } 
    return result(root->right, key);   
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
 
    int k; 
    cin >> k; 
 
    Node* target = result(root, k); 
    if (target != nullptr) { 
        Print(target);   
    } else { 
        cout << 0;   
    } 
 
    return 0; 
}