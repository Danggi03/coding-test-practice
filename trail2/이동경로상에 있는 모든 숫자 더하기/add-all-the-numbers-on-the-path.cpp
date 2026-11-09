#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// N E S W
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

bool ismatch(const int& x, const int& y, const int& size) {
    return !(x < 0 || x >= size || y < 0 || y >= size);
}

int main() {
    // input variable
    int n, cmd; 
    string t;
    cin >> n >> cmd >> t;

    vector<vector<int>> matrix (n, vector<int>(n, 0));
    pair<int, int> coor = make_pair(((n + 1) / 2) - 1, ((n + 1) / 2) - 1);
    int count;
    int angle = 0;
    
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            int var;
            cin >> var;
            matrix[x][y] = var;
        }
    }

    count = matrix[coor.first][coor.second];

    for(int freq = 0; freq < cmd; freq++) {
        // 90 degrees
        if(t[freq] == 'R') {
            angle = (angle + 1) % 4;
        }
        else if(t[freq] == 'L') {
            angle = (angle - 1 + 4) % 4;
        }
        else if(t[freq] == 'F') {
            int nx = coor.first + dx[angle],
                ny = coor.second + dy[angle];
                
            if(ismatch(nx, ny, n)) {
                coor.first += dx[angle];
                coor.second += dy[angle];

                count += matrix[coor.first][coor.second];
            }
        }
    }

    cout << count;
    
    return 0;
}