#include <iostream>
using namespace std;

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int nth_prime(int n) {
    int count = 0;  
    int num = 2;    
    while (true) {
        if (is_prime(num)) {
            count++;  
            if (count == n) {
                return num;  
            }
        }
        num++; 
    }
}

int main() {
    int n;
    cin >> n;
    cout << nth_prime(n) << endl;  
    return 0;
}