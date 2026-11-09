#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//E, S, W, N
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
using namespace std;

bool ismatch(const int& x, const int& y, const int& size) {
    return x > 0 && x < size && y > 0 && y < size;
}

int main() {
    // input variable
    int n, k;
    cin >> n;
    string mir;


    vector<vector<char>> matrix(n + 1, vector<char>(n + 1, 0));
    pair<int, int> coor = make_pair(1,1);
    int angle = 0;
    int reflex = 0;

    // init
    for(int x = 1; x < matrix.size(); x++) {
        int i = 0;
        cin >> mir;
        for(int y = 1; y < matrix.size(); y++, i++) {
            matrix[x][y] = mir.at(i);
        }
    }
    

    // index
    cin >> k;
    for(int i = 1; i < k; i ++) {
        int nx = coor.first + dx[angle],
            ny = coor.second + dy[angle];

        if(ismatch(nx, ny, matrix.size())) {
            coor.first += dx[angle];
            coor.second += dy[angle];
        }
        else {
            angle = (angle + 1) % 4;
        }
    }
    //angle refresh
    angle = (angle + 1) % 4;

    while(ismatch(coor.first, coor.second, matrix.size())) {
        reflex++;
        if(matrix[coor.first][coor.second] == '\\') {
            angle ^= 1;

            //move
            coor.first += dx[angle];
            coor.second += dy[angle];
        }
        else if(matrix[coor.first][coor.second] == '/') {
            angle ^= 3;
            //move
            coor.first += dx[angle];
            coor.second += dy[angle];
        }
    }

    cout << reflex;
    return 0;
}