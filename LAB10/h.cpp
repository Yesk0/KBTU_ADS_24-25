#include <bits/stdc++.h>

using namespace std;

const int MAX_DIM = 100;

char field[MAX_DIM][MAX_DIM]; // Сетка для представления островов
int rowCount, colCount;

// Функция для выполнения DFS и "затопления" текущего острова
void floodFill(int row, int col) {
    if (row < 0 || col < 0 || row >= rowCount || col >= colCount || field[row][col] == '0') {
        return;
    }

    field[row][col] = '0'; // Отмечаем ячейку как посещенную
    floodFill(row, col + 1); // Справа
    floodFill(row, col - 1); // Слева
    floodFill(row + 1, col); // Снизу
    floodFill(row - 1, col); // Сверху
}

int main() {
    int islandCount = 0;
    cin >> rowCount >> colCount;
    for (int row = 0; row < rowCount; row++)
        for (int col = 0; col < colCount; col++)
            cin >> field[row][col];
    for (int row = 0; row < rowCount; row++) for (int col = 0; col < colCount; col++)
            if (field[row][col] == '1') {
                floodFill(row, col); 
                islandCount++;
            }
    cout << islandCount;
    return 0;
}