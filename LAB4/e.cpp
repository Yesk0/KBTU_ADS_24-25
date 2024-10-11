#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getMaxWidth(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int maxWidth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        maxWidth = max(maxWidth, levelSize);  // Update maxWidth with current level's size

        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
    return maxWidth;
}

int main() {
    int n;
    cin >> n;

    unordered_map<int, TreeNode*> nodes;

    // Creating the tree
    for (int i = 1; i <= n; i++) {
        nodes[i] = new TreeNode(i);
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (z == 0) {
            nodes[x]->left = nodes[y];   // Left child
        } else {
            nodes[x]->right = nodes[y];  // Right child
        }
    }

    // Root of the tree is always node 1
    TreeNode* root = nodes[1];

    // Calculate and print the maximum width of the tree
    cout << getMaxWidth(root) << endl;

    return 0;
}