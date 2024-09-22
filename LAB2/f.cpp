#include <iostream>

using namespace std;

struct node{
    short val;
    node * next;

    node(short x){
        val = x;
        next = NULL;
    }
};

struct ll{
    node * head;
    node * tail;

    ll(){
        head = tail = NULL;
    }

    void add(short x){
        node * n = new node(x);

        if(head == NULL){
            head = tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
    }

    void insert(short k, short x){
        node * current  = head;

        node * n = new node(x);

        if(k==0){
            n->next = head;
            head = n;
        }else {

            for (short i = 1; i < k; i++) {
                current = current->next;
            }

            n->next = current->next;
            current->next = n;
        }
    }

    void list(){
        node * current = head;

        while(current != NULL){
            cout<<current->val<<" ";
            current = current->next;
        }
    }
};

int main(){
    short n, x, k;

    cin>>n;

    ll l;

    for(short i = 1; i <= n; i++){
        cin>>x;
        l.add(x);
    }

    cin>>x>>k;

    l.insert(k,x);

    l.list();

    return 0;
}