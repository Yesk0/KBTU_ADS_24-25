#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, x;
    cin>>n;

    vector<int> v;

    for(int i = 0; i < n; i++){
        cin>>x;
        v.push_back(x);
    }

    cin>>x;

    int l = 0;
    int r = n;

    while(l<r){
        int mid = (l+r)/2;

        if(x==v.at(mid)){
            cout<<"Yes";
            return 0;
        }else if(x<v.at(mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }

    cout<<"No";

    return 0;
}