#include <bits/stdc++.h>

using namespace std;

int find_the_shortest_path(vector<vector<int>> matrix, int start_point, int end_point){
    int size_of_matrix = matrix.size();
    vector<int> the_distance(size_of_matrix, -1); // минус один потому что типа нету дороги
    queue<int> road;
    the_distance[start_point] = 0;

    road.push(start_point);
    while(!road.empty()){
        int current_point = road.front();
        road.pop();

        for(int neighbor = 0; neighbor < size_of_matrix; neighbor++)
            if(matrix[current_point][neighbor] == 1 and the_distance[neighbor] == -1){
                the_distance[neighbor] = the_distance[current_point] + 1;

                road.push(neighbor);

                // Если дошли до конца то, можно вернуть минимальную дистанцию между вершинами
                if(neighbor == end_point) return the_distance[neighbor];
            }
    }
    return -1;
}

int main(){
    int size_of_matrix;
    cin >> size_of_matrix;
    vector<vector<int>> matrix(size_of_matrix, vector<int>(size_of_matrix));
    for(int i = 0; i < size_of_matrix; i++) for(int j = 0; j < size_of_matrix; j++) cin >> matrix[i][j];
    int start, end;
    cin >> start >> end;

    // минусуем на один просто потому что мне лень это делать в самой функции 
    start--; end--;

    cout << find_the_shortest_path(matrix, start, end);

    return 0;
}