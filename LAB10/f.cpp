#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> matrix;
vector<int> color;

void dfs_func(int change){
    color[change] = 1;
    for(int i : matrix[change]){
        if(color[i] == 0)
            dfs_func(i);
    }
}

int main(){
    int num_of_vertices, num_of_edges;
    cin >> num_of_vertices >> num_of_edges;
    matrix = vector<vector<int>>(num_of_vertices);
    color = vector<int>(num_of_vertices);
    for(int i = 0; i < num_of_edges; i++){
        int start_pnt, end_pnt;
        cin >> start_pnt >> end_pnt;
        start_pnt--; end_pnt--;
        matrix[start_pnt].push_back(end_pnt);
        matrix[end_pnt].push_back(start_pnt);
    }
    int s_vertic, f_vertic;
    cin >> s_vertic >> f_vertic;
    s_vertic--; f_vertic--;
    bool chck = false;
    dfs_func(s_vertic);

    for(int i = 0; i < num_of_vertices; i++) if(color[i] == 1 and i == f_vertic) chck = true;
    if(chck) cout << "YES";
    else cout << "NO";
    return 0;
}