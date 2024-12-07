#include <bits/stdc++.h>

using namespace std;

vector<int> graph[501], cycleNodes;
int visitStatus[501]; // 0 - не посещено, 1 - в процессе, 2 - завершено
stack<int> pathStack;
bool hasCycle = false;

bool detectCycle(int node, int skipFrom, int skipTo) {
    visitStatus[node] = 1; // Узел в процессе посещения
    for (int neighbor : graph[node]) {
        if (node == skipFrom && neighbor == skipTo) continue; // Пропустить ребро
        if (visitStatus[neighbor] == 0) { // Если сосед не посещен
            if (detectCycle(neighbor, skipFrom, skipTo)) return true;
        } else if (visitStatus[neighbor] == 1) { // Если сосед в процессе посещения, найден цикл
            return true;
        }
    }
    visitStatus[node] = 2; // Завершили посещение узла
    return false;
}

bool extractCycle(int node) {
    visitStatus[node] = 1;
    pathStack.push(node);

    for (int neighbor : graph[node]) {
        if (visitStatus[neighbor] == 0) {
            if (extractCycle(neighbor)) return true;
        } else if (visitStatus[neighbor] == 1) { // Цикл найден
            // Формируем путь
            while (pathStack.top() != neighbor) {
                cycleNodes.push_back(pathStack.top());
                pathStack.pop();
            }
            cycleNodes.push_back(neighbor);
            cycleNodes.push_back(node);
            reverse(cycleNodes.begin(), cycleNodes.end());
            return true;
        }
    }

    visitStatus[node] = 2;
    if (!pathStack.empty()) {
        pathStack.pop();
    }

    return false;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    // Считывание графа
    for (int i = 0; i < edges; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    // Поиск цикла
    for (int i = 1; i <= nodes; i++) {
        if (visitStatus[i] == 0) {
            hasCycle = extractCycle(i);
            if (hasCycle) {
                break;
            }
        }
    }

    if (!hasCycle) {
        cout << "YES";
        return 0;
    }

    // Проверяем, можно ли убрать цикл, удалив одно ребро
    for (int i = 0; i < cycleNodes.size() - 1; i++) {
        int skipFrom = cycleNodes[i];
        int skipTo = cycleNodes[i + 1];

        fill(begin(visitStatus), end(visitStatus), 0); // Сброс статуса посещения

        hasCycle = false;
        for (int j = 1; j <= nodes; j++) {
            if (visitStatus[j] == 0) {
                hasCycle |= detectCycle(j, skipFrom, skipTo);
            }
        }

        if (!hasCycle) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}