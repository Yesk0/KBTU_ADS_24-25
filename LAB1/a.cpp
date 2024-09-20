#include <iostream>
#include <queue>
using namespace std;

int main(){
    int t,n;
    cin>>t;

    queue<int> requests;

    for(int i = 0; i < t; i++){
        cin>>n;
        requests.push(n);
    }

    while(!requests.empty()){
        n = requests.front();

        deque<int> cards;
        cards.push_front(n);

        while(n>1){
            n--;

            cards.push_front(n);

            for(int i = 0; i < n; i++){
                cards.push_front(cards.back());
                cards.pop_back();
            }
        }

        while(!cards.empty()){
            cout<<cards.front()<<" ";
            cards.pop_front();
        }

        cout<<endl;

        requests.pop();
    }




    return 0;
}