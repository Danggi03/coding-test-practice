#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// North, East, South, West // mathic
// east , south, west, north // codding
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// 0 <= x < size && 0 <= y < size
bool isrange(const int& x, const int& y, const int& size) {
    return x >= 0 && x < size && y >= 0 && y < size;
}

int main() {
    // input variable
    int n;
    cin >> n;
    
    vector<vector<int>> arr(n, vector<int>(n, 0));
    int var = 0;

    // init
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            int var;
            cin >> var;
            arr[x][y] = var;
        }
    }

    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            int check = 0;
            for(int angle = 0; angle < 4; angle++) {
                int nx = x + dx[angle], ny = y + dy[angle];
                if(isrange(nx, ny, n) && arr[nx][ny] == 1)
                    check++;
            }
            if(check >= 3)
                var++;
        }
    }

    cout << var;



    return 0;
}