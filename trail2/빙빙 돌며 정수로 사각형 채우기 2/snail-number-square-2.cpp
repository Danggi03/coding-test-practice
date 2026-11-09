#include <iostream>
#include <vector>
#include <algorithm>

// S E N W
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using namespace std;

// xsize ysize, each n and m
bool ismatch(const int& x, const int& y, const int& xSize, const int& ySize) {
    return x >= 0 && x < xSize && y >= 0 && y < ySize;
}
int main() {
    // input variable
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    pair<int, int> coor = make_pair(0, 0);
    int angle = 0;
    
    matrix[0][0] = 1;
    
    for(int freq = 1; freq < n * m; freq++) {
        int temp = matrix[coor.first][coor.second];
        int nx = coor.first + dx[angle],
            ny = coor.second + dy[angle];
        
        if(!ismatch(nx, ny, n, m) || matrix[nx][ny] != 0)
            angle = (angle + 1) % 4;
        
        coor.first += dx[angle];
        coor.second += dy[angle];
        matrix[coor.first][coor.second] = temp + 1;
    }

    for(auto& row : matrix) {
        for(auto& var : row) {
            cout << var << " ";
        }
        cout << "\n"; 
    }
    return 0;
}