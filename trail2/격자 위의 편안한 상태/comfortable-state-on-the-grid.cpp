#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// N E S W codding ver
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool ismatch(const int& x, const int& y, const int& size) {
    return x > 0 && x < size && y > 0 && y < size;
}

bool iscomfortant(const vector<vector<bool>>& matrix, const int& x, const int& y) {
    int count = 0;
    for(int angle = 0; angle < 4; angle++) {
        int nx = x + dx[angle],
            ny = y + dy[angle];
        
        if(ismatch(nx, ny, matrix.size()) && matrix[nx][ny] == true) {
            count++;
        }
    }

    if(count == 3) 
        return true;
    else
        return false;
}
int main() {
    // input variable
    int n, m;
    cin >> n >> m;
    
    vector<vector<bool>> matrix (n + 1, vector<bool>(n + 1, false));

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        matrix[x][y] = true;

        cout << iscomfortant(matrix, x, y) << "\n";
    }
    return 0;
}