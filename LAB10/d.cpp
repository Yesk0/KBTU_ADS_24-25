#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 5009;
const int UNVISITED = 0, VISITED = 1;
int distanceFromSource[MAX_NODES], nodeColor[MAX_NODES];
vector<int> adjacencyList[MAX_NODES];
bool isNodeProcessed[MAX_NODES];

void initialize_distances(int totalNodes) {
    for (int i = 1; i <= totalNodes; i++) {
        distanceFromSource[i] = INT_MAX;
    }
}

void add_edge(int startNode, int endNode) {
    adjacencyList[startNode].push_back(endNode);
    adjacencyList[endNode].push_back(startNode);
}

void perform_bfs(int startNode) {
    queue<int> nodeQueue;
    nodeQueue.push(startNode);
    isNodeProcessed[startNode] = true;
    distanceFromSource[startNode] = 0;

    while (!nodeQueue.empty()) {
        int currentNode = nodeQueue.front();
        nodeQueue.pop();

        for (int i = 0; i < adjacencyList[currentNode].size(); i++) {
            int adjacentNode = adjacencyList[currentNode][i];
            if (distanceFromSource[adjacentNode] > distanceFromSource[currentNode] + 1) {
                distanceFromSource[adjacentNode] = distanceFromSource[currentNode] + 1;
                isNodeProcessed[adjacentNode] = true;
                nodeQueue.push(adjacentNode);
            }
        }
    }
}

void handle_query(int queryType, int node) {
    if (queryType == 1) {
        if (nodeColor[node] != VISITED) {
            perform_bfs(node);
            nodeColor[node] = VISITED;
        }
    } else {
        if (distanceFromSource[node] == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << distanceFromSource[node] << endl;
        }
    }
}

int main() {
    int totalNodes, totalEdges, totalQueries;
    cin >> totalNodes >> totalEdges >> totalQueries;

    for (int i = 1; i <= totalEdges; i++) {
        int startNode, endNode;
        cin >> startNode >> endNode;
        add_edge(startNode, endNode);
    }

    initialize_distances(totalNodes);

    while (totalQueries--) {
        int queryType, node;
        cin >> queryType >> node;
        handle_query(queryType, node);
    }

    return 0;
}