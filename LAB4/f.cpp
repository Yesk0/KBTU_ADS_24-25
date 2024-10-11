#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int countTriangles(TreeNode* root) {
    if (!root) return 0;

    int triangles = 0;
    if (root->left && root->right) {
        triangles++;  // Found a node with both left and right children
    }

    // Recursively check left and right subtrees
    triangles += countTriangles(root->left);
    triangles += countTriangles(root->right);

    return triangles;
}

int main() {
    int N;
    cin >> N;

    TreeNode* root = nullptr;

    // Insert nodes into BST
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    // Count and print the number of mini-triangles
    cout << countTriangles(root) << endl;

    return 0;
}
