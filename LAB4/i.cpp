#include <iostream>
#include <map>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    map<int, int> bst;  // A map to simulate a BST with multiplicity

    while (Q--) {
        string command;
        int X;
        cin >> command >> X;

        if (command == "insert") {
            // Insert X: increment its multiplicity in the map
            bst[X]++;
        } else if (command == "delete") {
            // Delete X: decrement its multiplicity, if it exists
            if (bst[X] > 0) {
                bst[X]--;
                if (bst[X] == 0) {
                    bst.erase(X);  // Remove key if multiplicity becomes 0
                }
            }
        } else if (command == "cnt") {
            // Output the multiplicity of X
            cout << bst[X] << endl;
        }
    }

    return 0;
}