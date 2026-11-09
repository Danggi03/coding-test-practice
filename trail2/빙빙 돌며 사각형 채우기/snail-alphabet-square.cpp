#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// E S W N
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool ismatch(const int& x, const int& y, const int& xSize, const int& ySize) {
    return x >= 0 && x < xSize && y >= 0 && y < ySize;
}

int main() {
    // input variable
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> matrix (n, vector<char>(m, 0));
    pair<int, int> coor = make_pair(0, 0);
    int angle = 0;

    matrix[0][0] = (char) 65;

    for(int i = 1; i < n * m; i++) {
        char temp = matrix[coor.first][coor.second];
        int nx = coor.first + dx[angle],
            ny = coor.second + dy[angle];

        if(!ismatch(nx, ny, n, m) || matrix[nx][ny] != 0)
            angle = (angle + 1) % 4;
        
        coor.first += dx[angle];
        coor.second += dy[angle];
        
        if(temp + (char) 1 == 91)
            matrix[coor.first][coor.second] = (char) 65;
        else
            matrix[coor.first][coor.second] = temp + (char) 1;
    }

    for(auto& row : matrix) {
        for(auto& var : row) {
            cout << var << " ";
        }
        cout << "\n";
    }
    

    return 0;
}