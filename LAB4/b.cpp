#include <iostream>

using namespace std;

struct node{
    int value;
    node * left;
    node * right;

    node(int x){
        this->value = x;
        this->left = this->right = NULL;
    }
};

struct binary_tree{
    public:
        binary_tree(){
            this->root = NULL;
        }

        void add(int x){
            node * result = add(this->root, x);
            if(this->root == NULL)
                this->root = result;
        }

        int calculate_subtree_size(int x){
            node * current = search(x, this->root);
//            cout<<current->value;
            return calculate_sub_tree_size(current);

        }

        void print(){
            this->print(this->root);
        }
    private:
        node * root;

        int calculate_sub_tree_size(node * n){

            int sum = 1;
            if (n->left != NULL)
                sum += calculate_sub_tree_size(n->left);
            if (n->right != NULL)
                sum += calculate_sub_tree_size(n->right);



            return sum;
        }

        node * search(int x, node * n){
//            cout<<root->value;
//            cout<<x;

            if(x == n->value)
                return n;
            else if (x < n->value)
                return search(x, n->left);
            else if (x > n->value)
                return search(x, n->right);
        }

        node * add(node * current, int x){
            if(current == NULL){
                current = new node(x);
            }else if(x < current->value){
                if(current->left == NULL)
                    current->left = add(current->left, x);
                else
                    add(current->left, x);
            }else if(x > current->value){
                if(current->right == NULL)
                    current->right = add(current->right, x);
                else
                    add(current->right, x);
            }
            return current;
        }

        void print(node * n){
            if(n != NULL){
                print(n->left);
                cout<<n->value<<" ";
                print(n->right);
            }
        }
};

int main(){
    short n;
    int x;
    cin>>n;

    binary_tree * bt = new binary_tree();

    for(short i = 0; i < n; i++){
        cin>>x;
        bt->add(x);
    }

    cin>>x;

//    bt->print();
    cout<<bt->calculate_subtree_size(x);


    return 0;
}