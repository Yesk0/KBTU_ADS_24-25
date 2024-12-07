#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> compatibilityMatrix;

vector<vector<int>> read_compatibility_matrix(int elementCount) {
    vector<vector<int>> matrix(elementCount, vector<int>(elementCount));
    for (int row = 0; row < elementCount; row++) for (int col = 0; col < elementCount; col++) cin >> matrix[row][col];
    return matrix;
}

bool can_combine_elements(int elementA, int elementB, int elementC) {
    return compatibilityMatrix[elementA][elementB] == 1 and
           compatibilityMatrix[elementA][elementC] == 1 and
           compatibilityMatrix[elementB][elementC] == 1;
}

void handle_queries(int queryCount) {
    while (queryCount--) {
        int element1, element2, element3;
        cin >> element1 >> element2 >> element3;
        element1--; element2--; element3--;
        if (can_combine_elements(element1, element2, element3)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    int elementCount, queryCount;
    cin >> elementCount >> queryCount;

    compatibilityMatrix = read_compatibility_matrix(elementCount);

    handle_queries(queryCount);

    return 0;
}