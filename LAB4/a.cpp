#include <iostream>
#include <queue>


using namespace std;


struct node{
    int value;
    node * left;
    node * right;

    node(int x){
        value = x;
        left = right = NULL;
    }
};

struct binary_tree{
    public:
        binary_tree(){
            this->root = NULL;
        }

        void add(int x){
            node * result = this->add(this->root, x);
            if(this->root == NULL){
                this->root = result;
            }
        }

        void print(){
            this->print(this->root);
        }

        bool possible_direction(string direction){
            node * current = this->root;
            for(int i = 0; i < direction.length(); i++){

                if(direction[i] == 'L'){
                    if(current->left != NULL)
                        current = current->left;
                    else
                        return false;
                }else{
                    if(current->right != NULL)
                        current = current->right;
                    else
                        return false;
                }
            }

            return true;
        }

    private:
        node * root;

        node * add(node * current, int x){
            if(current == NULL){
                current = new node(x);
            }else if(current->value > x){
                if(current->left == NULL){
                    current->left = add(current->left, x);
                }else{
                    add(current->left, x);
                }
            }else if(current->value < x){
                if(current->right == NULL){
                    current->right = add(current->right, x);
                }else{
                    add(current->right, x);
                }
            }

            return current;
        }

        void print(node * current){
            if(current != NULL){
                print(current->left);
                cout<<current->value<<" ";
                print(current->right);
            }
        }
};


int main(){
    int n, m, x;

    cin>>n>>m;

    binary_tree * bt = new binary_tree();

    for(int i = 1; i <= n; i++){
        cin>>x;
        bt->add(x);
    }

    queue<string> requests;

    string s;

    for(int i = 1; i <= m; i++){
        cin>>s;
        requests.push(s);
    }

    while(!requests.empty()){
        if(bt->possible_direction(requests.front())){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        requests.pop();
    }
    return 0;
}