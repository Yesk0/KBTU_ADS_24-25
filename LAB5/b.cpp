#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, x;
    priority_queue<int> pq;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>x;
        pq.push(x);
    }

    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a-b);

    }

    cout<<pq.top();

    return 0;
}