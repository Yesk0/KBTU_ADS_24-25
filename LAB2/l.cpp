#include <iostream>
#include <limits.h>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

int findMaxSum(Node* head) {
    if (head == nullptr) return 0;

    int maxSum = INT_MIN;
    int currentSum = 0;

    Node* current = head;
    while (current != nullptr) {
        currentSum += current->value;

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }

        if (currentSum < 0) {
            currentSum = 0;
        }

        current = current->next;
    }

    return maxSum;
}

Node* createLinkedList(int arr[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        Node* newNode = new Node(arr[i]);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    int n;
    cin >> n; 
    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; 
    }

    Node* head = createLinkedList(arr, n);

    int maxSum = findMaxSum(head);
    cout << maxSum << endl;

    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
