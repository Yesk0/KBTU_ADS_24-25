#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = right = nullptr;
    }
};

// Function to insert a new node in the BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

// Reverse in-order traversal and update the keys
void updateBST(Node* root, int &sum) {
    if (root == nullptr) return;

    // Traverse the right subtree first (greater elements)
    updateBST(root->right, sum);

    // Update the current node's key
    sum += root->key;
    root->key = sum;

    // Traverse the left subtree (smaller elements)
    updateBST(root->left, sum);
}

// Reverse in-order traversal to print the updated BST keys in decreasing order
void reverseInorderTraversal(Node* root) {
    if (root == nullptr) return;

    reverseInorderTraversal(root->right);  // First visit the right subtree
    cout << root->key << " ";              // Then visit the root
    reverseInorderTraversal(root->left);   // Finally visit the left subtree
}

int main() {
    int n;
    cin >> n;

    vector<int> keys(n);
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    Node* root = nullptr;
    // Build the BST
    for (int key : keys) {
        root = insert(root, key);
    }

    int sum = 0;
    // Update the BST by replacing node keys with the sum of greater or equal nodes
    updateBST(root, sum);

    // Perform reverse in-order traversal to print the keys in decreasing order
    reverseInorderTraversal(root);
    cout << endl;

    return 0;
}