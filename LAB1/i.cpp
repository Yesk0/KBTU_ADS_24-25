#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    string votes;
    cin >> votes;
    
    queue<int> s_queue, k_queue;
    
    // Fill the queues with the initial positions of 'S' and 'K'
    for (int i = 0; i < n; ++i) {
        if (votes[i] == 'S') {
            s_queue.push(i);
        } else {
            k_queue.push(i);
        }
    }
    
    // Simulate the process
    while (!s_queue.empty() && !k_queue.empty()) {
        int s_front = s_queue.front();
        int k_front = k_queue.front();
        s_queue.pop();
        k_queue.pop();
        
        // The one with the smaller index eliminates the other
        if (s_front < k_front) {
            s_queue.push(s_front + n);  // Re-enter at the back of the line
        } else {
            k_queue.push(k_front + n);  // Re-enter at the back of the line
        }
    }
    
    // Determine the winner
    if (!s_queue.empty()) {
        cout << "SAKAYANAGI" << endl;
    } else {
        cout << "KATSURAGI" << endl;
    }
    
    return 0;
}
