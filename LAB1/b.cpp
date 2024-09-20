#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n, a;
    cin >> n;

    queue<int> numbers;

    for (int i = 0; i < n; i++) {
        cin >> a;
        numbers.push(a);
    }

    stack<int> previous;

    while (!numbers.empty()) {
        a = numbers.front();
        numbers.pop();

        while (!previous.empty() && previous.top() > a) {
            previous.pop();
        }

        if (previous.empty()) {
            cout << "-1 ";
        } else {
            cout << previous.top() << " ";
        }

        previous.push(a);
    }

    return 0;
}
