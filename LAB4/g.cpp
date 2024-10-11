#include <iostream>
using namespace std;

struct Node
{
    Node* right;
    Node* left;
    int value;
    Node(int value){
        this->value = value;
        right = NULL;
        left = NULL;

    }

};


Node* insert(Node* root, int value){
    if(root == NULL){
        return new Node(value);
    }
    if(root->value > value){
        root->left = insert(root->left, value);

    }
    if(root->value < value){
        root->right = insert(root->right, value);
    }
    return root;
}

int heightTree(Node* root){
    if(root == NULL){
        return 0;
    }
    return(max(heightTree(root->left), heightTree(root->right)) + 1);
}


int distanceTree(Node* root){
    if(root == NULL){
        return 0;
    }
    int maxDistance = heightTree(root->left) + heightTree(root->right) + 1;
    return max(maxDistance, max(distanceTree(root->left), distanceTree(root->right)));
}



int main(){
    int n;
    cin >> n;
    int val;
    Node * root = NULL;
    for(int i = 0; i < n; i++){
        cin >> val;
        root = insert(root, val);
    }

    cout << distanceTree(root);
}