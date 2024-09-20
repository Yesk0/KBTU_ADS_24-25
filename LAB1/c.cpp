#include<bits/stdc++.h>
using namespace std;

string processString(const string& str){
    stack<char> s;
    for(char c:str){
        if(c=='#'){
            if(!s.empty()){
                s.pop();
            }
        }
        else{
            s.push(c);
        }
    }
    string result;
    while(!s.empty()){
        result = s.top()+result;
        s.pop();
    }
    return result;
} 
int main() {
    string s1, s2;
    cin>>s1>>s2;
    if(processString(s1) == processString(s2)){
        cout << "Yes\n"; 
    }
    else{
        cout << "No\n";
    }
    return 0;
}
