#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n;
    unsigned long long t;
    cin>>n;
    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long> > pq;

    for(int i = 0; i < n; i++){
        cin>>t;
        pq.push(t);
    }

    unsigned long long sum = 0;

    while(pq.size()>1){
        unsigned long long a = pq.top();
        pq.pop();
        unsigned long long b = pq.top();
        pq.pop();
        unsigned long long s = a + b;
        pq.push(s);
        sum += s;
    }

    cout<<sum;

    return 0;
}