#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1e5 + 1;

vector<int> graph[MAX_NODES], topoSort;
int nodeStatus[MAX_NODES]; // 0 - не посещен, 1 - в процессе, 2 - завершен

// Рекурсивная функция для поиска топологического порядка
void performDFS(int node) {
    if (nodeStatus[node] == 1) { 
        cout << "Impossible" << endl;
        exit(0);
    }

    if (nodeStatus[node] == 2) return;

    nodeStatus[node] = 1; 

    for (int neighbor : graph[node]) performDFS(neighbor);

    nodeStatus[node] = 2; // Завершили обработку узла
    topoSort.push_back(node); // Добавляем в топологический порядок
}

int main() {
    int nodeCount, edgeCount;
    cin >> nodeCount >> edgeCount;

    for (int i = 0; i < edgeCount; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    for (int node = 1; node <= nodeCount; node++)
        if (nodeStatus[node] == 0)
            performDFS(node);

    cout << "Possible" << endl;

    reverse(topoSort.begin(), topoSort.end());
    for (int node : topoSort)
        cout << node << " ";

    return 0;
}