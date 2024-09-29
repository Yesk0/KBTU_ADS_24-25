#include <iostream>
#include <queue>

using namespace std;


int main(){
    short t, n, m, l, r, mid;
    int x;

    cin>>t;

    queue<int> coordinates;

    for(short i = 0; i < t; i++){
        cin>>x;
        coordinates.push(x);
    }

    cin>>n>>m;

    int snake[n][m];

    for(short i = 0; i < n; i++){
        for(short j = 0; j < m; j++){
            cin>>snake[i][j];
        }
    }

    while(!coordinates.empty()){
        x = coordinates.front();

        bool founded = false;

        /// i even -> ascending order; i odd -> descending order
        for(short i = 0; i < n; i++){
            if(founded)
                break;

            l = 0;
            r = m;

            while(l<r){
                mid = (l+r)/2;

                if(x == snake[i][mid]){
                    cout<<i<<" "<<mid<<endl;
                    founded = true;
                    break;
                }else if(x < snake[i][mid]){
                    if(i%2==0)
                        l = mid + 1;
                    else
                        r = mid;
                }else{
                    if(i%2==0)
                        r = mid;
                    else
                        l = mid + 1;
                }
            }
        }

        if(!founded)
            cout<<-1<<endl;

        coordinates.pop();

    }

    return 0;
}