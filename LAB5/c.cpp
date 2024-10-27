#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, x, t;
    cin>>n>>x;

    priority_queue<int> free_places;

    for(int i = 0; i < n; i++){
        cin>>t;
        free_places.push(t);
    }

    unsigned long long sum = 0;

    for(int i = 0; i < x; i++){
        t = free_places.top();
        sum += t;
        free_places.pop();
        free_places.push(t-1);
    }

    cout<<sum;

    return 0;
}