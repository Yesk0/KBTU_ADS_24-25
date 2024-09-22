#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int x) {
        value = x;
        next = nullptr;
    }
};

struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList() {
        head = tail = nullptr;
    }

    void add(int x) {
        Node* n = new Node(x);
        if (head == nullptr) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    void deleteEverySecond() {
        if (head == nullptr) return; 

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->next != nullptr) {
            prev = current;          
            current = current->next;  

            prev->next = current->next;
            delete current;

            current = prev->next;
        }
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;

    int n;
    cin >> n; 

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        ll.add(value);
    }

    ll.deleteEverySecond();

    ll.print();

    return 0;
}
