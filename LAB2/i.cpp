#include <iostream>
#include <string>

using namespace std;

struct Node {
    string book;
    Node* next;
    Node* prev;

    Node(string b) : book(b), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void add_front(string book) {
        Node* newNode = new Node(book);
        if (size == 0) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
        cout << "ok" << endl;
    }

    void add_back(string book) {
        Node* newNode = new Node(book);
        if (size == 0) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        cout << "ok" << endl;
    }

    void erase_front() {
        if (size == 0) {
            cout << "error" << endl;
        } else {
            Node* temp = head;
            cout << head->book << endl;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            size--;
        }
    }

    void erase_back() {
        if (size == 0) {
            cout << "error" << endl;
        } else {
            Node* temp = tail;
            cout << tail->book << endl;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
            size--;
        }
    }

    void front() {
        if (size == 0) {
            cout << "error" << endl;
        } else {
            cout << head->book << endl;
        }
    }

    void back() {
        if (size == 0) {
            cout << "error" << endl;
        } else {
            cout << tail->book << endl;
        }
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
        cout << "ok" << endl;
    }

    void exit() {
        cout << "goodbye" << endl;
    }
};

int main() {
    DoublyLinkedList books;
    string command, bookName;

    while (cin >> command) {
        if (command == "add_front") {
            cin >> bookName;
            books.add_front(bookName);
        } else if (command == "add_back") {
            cin >> bookName;
            books.add_back(bookName);
        } else if (command == "erase_front") {
            books.erase_front();
        } else if (command == "erase_back") {
            books.erase_back();
        } else if (command == "front") {
            books.front();
        } else if (command == "back") {
            books.back();
        } else if (command == "clear") {
            books.clear();
        } else if (command == "exit") {
            books.exit();
            break;
        }
    }

    return 0;
}
