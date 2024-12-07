#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    short n;
    unsigned long long h;
    cin>>n;
    vector<unsigned long long> hashes;

    while(n > 0){
        n--;
        cin>>h;
        hashes.push_back(h);
    }

    for(vector<unsigned long long>::iterator it = hashes.begin(); it < hashes.end(); it++){
        h = *it;

        if(it != hashes.begin())
            h -= *(it-1);

        h /= pow(2, it-hashes.begin());

        h += 97;

        cout<<(char)h;
    }

    return 0;
}