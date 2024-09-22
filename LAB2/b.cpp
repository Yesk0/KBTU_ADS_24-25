#include <iostream>

using namespace std;

struct node{
    string v;
    node * next;

    node(string x){
        v = x;
        next = NULL;
    }
};

struct ll{
    node * tail;
    node * head;

    ll(){
        tail = head = NULL;
    }

    void add(string x){
        node * n = new node(x);
        if(head==NULL){
            head = tail = n;
        }else{
            n->next = head;  //cyclic list
            tail->next = n;
            tail = n;
        }
    }

    void print_with_offset(int k){
        node * current = head;

        for(int i = 1; i < k; i++){
            current = current->next;
        }

        node * tmp_next = current->next;
        current->next = NULL;  /// end of the list
        current = tmp_next;


        while(current != NULL){
            cout<<current->v<<" ";
            current = current->next;
        }
    }
};

int main(){
    int n, k;
    string s;
    cin>>n>>k;

    ll l;

    for(int i = 1; i <= n; i++){
        cin>>s;
        l.add(s);
    }

    l.print_with_offset(k);


    return 0;
}