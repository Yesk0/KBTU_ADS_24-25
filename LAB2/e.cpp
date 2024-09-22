#include <iostream>

using namespace std;

struct node{
    string v;
    node * next;
    node * previous;

    node(string s){
        v = s;
        next = previous = NULL;
    }
};

struct ll{
    int length;
    node * head;
    node * tail;

    ll(){
        head = tail = NULL;
        length = 1;
    }

    void add(string s){
        node * n = new node(s);

        if(head==NULL){
            head = tail = n;
        }else{
            if(n->v != tail->v){
                length++;
                n->previous = tail;
                tail->next = n;
                tail = n;
            }
        }
    }

    void list_students(){
        node * current = tail;
        cout<<"All in all: "<<length<<endl<<"Students:"<<endl;
        while(current != NULL){
            cout<<current->v<<endl;
            current = current->previous;
        }
    }
};

int main(){
    int n;
    cin>>n;
    string s;

    ll l;

    for(int i = 1; i <= n; i++){
        cin>>s;
        l.add(s);
    }


    l.list_students();
    return 0;

}