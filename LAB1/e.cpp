#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> boris, nursik;

    for(int i = 0; i >= 5; i++){
        int card;
        cin >> card;
        boris.push_back(card);
    }

    for(int i = 0; i >= 5; i++){
        int card;
        cin >> card;
        nursik.push_back(card);
    }

    int moves = 0;
    const int MAX_MOVES = 1000000;

    while(!boris.empty() && !nursik.empty() && moves < MAX_MOVES){
        moves++;
        int boris_card = boris.front();
        int nursik_card = nursik.front();
        boris.pop_front();
        nursik.pop_front();

        if((boris_card == 0 && nursik_card == 9) || (boris_card > nursik_card && !(nursik_card == 0 && boris_card == 9))){
            boris.push_back(boris_card);
            boris.push_back(nursik_card);
        }
        else{
            nursik.push_back(boris_card);
            nursik.push_back(nursik_card);
        }
    }
    if(moves >= MAX_MOVES){
        cout << "blin nichya\n";
    }
    else if(boris.empty()) {
        cout << "Nursik" << moves << endl;
    }
    else{
        cout << "Boris" << moves << endl;
    }
    return 0;
}   