#include <iostream> 
#include <cstdint> 
using namespace std; 
 
int MinSubarray(int n, int k){ 
    int a[n]; 
    int st = 0; 
    int end = 0; 
    int sum = 0; 
    int minLength = n+1; 
 
    for (int i = 0; i < n; i++){ 
        cin >> a[i]; 
    } 
 
    while(end < n){ 
        sum += a[end]; 
        end++; 
        while(sum >= k){ 
            minLength = min(minLength, end - st); 
            sum -= a[st]; 
            st++; 
        } 
    } 
    return minLength; 
     
     
} 
int main(){ 
    int n; 
    cin >> n; 
    int k; 
    cin >> k; 
 
 
    int res = MinSubarray(n, k); 
    cout << res; 
     
 
}