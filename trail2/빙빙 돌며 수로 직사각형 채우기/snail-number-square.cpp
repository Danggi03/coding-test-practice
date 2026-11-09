#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// E, S, W, N
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool ismatch(const int& x, const int& y, const int& sizeX, const int& sizeY) {
    return x >= 0 && x < sizeX && y >= 0 && y < sizeY;
}


int main() {
    // input variable
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    pair<int, int> coor = make_pair(0, 0);
    // EAST way start
    int angle = 0;
    
    //init
    matrix[coor.first][coor.second] = 1;

    for(int i = 1; i < n * m; i++) {
        int nx = coor.first + dx[angle],
            ny = coor.second + dy[angle];
        
        if(!ismatch(nx, ny, n, m) || matrix[nx][ny] != 0)
            angle = (angle + 1) % 4;

        coor.first += dx[angle];
        coor.second += dy[angle];
        matrix[coor.first][coor.second] = matrix[coor.first - dx[angle]][coor.second - dy[angle]] + 1;
    }
    
    for(auto& row : matrix) {
        for(auto& var : row) {
            cout << var << " ";
        }
        cout << "\n";
    }
    return 0;
}