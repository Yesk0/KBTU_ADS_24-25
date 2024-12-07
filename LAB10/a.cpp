#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


// Функция для проверки, остались ли грибы на поле, для того чтобы написать окончательный ответ
bool contain_one(const vector<vector<int>>& field) {
    for (const auto& row : field) for (int cell : row) if (cell == 1) return true;
    return false;
}

// Функция для чтения поля и начальных позиций Марио, используем очередь внутри которого пара чтобы запомнить все позиции
void read_field(int rows_size, int column_size, vector<vector<int>>& field, queue<pair<int, int>>& q) {
    for (int i = 0; i < rows_size; i++) for (int j = 0; j < column_size; j++){
            cin >> field[i][j];
            if (field[i][j] == 2) q.push({i, j});
    }
}

// Алгоритм BFS для уничтожения всех грибов на поле
int bfs(int rows_size, int column_size, vector<vector<int>>& field, queue<pair<int, int>>& q) {
    int minutes = 0;

    while (!q.empty()) {
        int size = q.size();
        bool progress = false;

        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();

            for (const auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && nx < rows_size && ny >= 0 && ny < column_size && field[nx][ny] == 1) {
                    field[nx][ny] = 2; // Новый Марио занимает место гриба, чтобы функция contain_one работал нормально
                    q.push({nx, ny}); // Тут сохраняем пару кординат в котором находились грибы
                    progress = true;
                }
            }
        }

        if (progress) minutes++;
    }

    return minutes;
}

// Основная функция для подсчёта минимального времени чтобы убить все грибы на карте
int calculate_time_to_kill_mushrooms(int rows_size, int column_size) {
    vector<vector<int>> field(rows_size, vector<int>(column_size));
    queue<pair<int, int>> q;

    read_field(rows_size, column_size, field, q);
    int minutes = bfs(rows_size, column_size, field, q);

    return contain_one(field) ? -1 : minutes;
}

int main() {
    int rows_size, column_size;
    cin >> rows_size >> column_size;

    int result = calculate_time_to_kill_mushrooms(rows_size, column_size);
    cout << result << endl;

    return 0;
}