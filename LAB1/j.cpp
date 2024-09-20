#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;  // Create a deque to store the numbers
    char operation;
    int num;

    while (cin >> operation) {  // Read until there is input
        if (operation == '+') {
            cin >> num;
            dq.push_front(num);  // Add to the front
        } 
        else if (operation == '-') {
            cin >> num;
            dq.push_back(num);  // Add to the back
        } 
        else if (operation == '*') {
            if (dq.size() >= 2) {
                int sum = dq.front() + dq.back();  // Sum of front and back
                cout << sum << endl;
                dq.pop_front();  // Remove front element
                dq.pop_back();   // Remove back element
            } else if (dq.size() == 1){
                int sum = dq.front() * 2;
                cout << sum << endl;
                dq.pop_front(); 
            }else{
                cout << "error" << endl;  // Not enough elements to sum
            }
        }
        else if (operation == '!') {
            break;  // End of input
        }
    }

    return 0;
}
