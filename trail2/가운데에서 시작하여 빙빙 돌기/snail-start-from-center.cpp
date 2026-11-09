#include <iostream>
#include <vector>
#include <algorithm>

// E N W S
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
using namespace std;

int main() {
    // input variable
    int n;
    cin >> n;
    
    vector<vector<int>> matrix (n, vector<int>(n, 0));
    pair<int, int> coor = make_pair(((n + 1) / 2) - 1, ((n + 1) / 2) - 1);
    int angle = 0;

    matrix[coor.first][coor.second] = 1;

    for(int i = 1; i < n * n; i++) {
        coor.first += dx[angle];
        coor.second += dy[angle];

        int next_angle = (angle + 1) % 4;
        int nx = coor.first + dx[next_angle],
            ny = coor.second + dy[next_angle];

        matrix[coor.first][coor.second] = matrix[coor.first - dx[angle]][coor.second - dy[angle]] + 1;

        if(matrix[nx][ny] == 0)
            angle = (angle + 1) % 4;
    }

    for(auto& row : matrix) {
        for(auto& var : row) {
            cout << var << " ";
        }
        cout << "\n";
    }
    return 0;
}