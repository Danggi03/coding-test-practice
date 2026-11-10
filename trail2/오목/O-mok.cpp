#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


pair<int, int> checking(const vector<vector<int>>& grid, const int& x, const int& y) {
    int status = grid[x][y];

    if(status == 0) {
        return make_pair(-1, -1);
    }
    if(y < 15) {
    // row
        for(int i = 1; i <= 4; i++) {
            if(grid[x][y + i] != status) {
                break;
            }
            if(i == 4)
                return make_pair(x, y + 2);
        }
    }

    // col
    if(x < 15) {
        for(int i = 1; i <= 4; i++) {
            if(grid[x + i][y] != status) {
                break;
            }
            if(i == 4)
                return make_pair(x + 2, y);
        }
    }


    // either row, col
    if(x < 15 && y < 15) {
        for(int i = 1; i <= 4; i++) {
            if(grid[x + i][y + i] != status) {
                break;
            }
            if(i == 4)
                return make_pair(x + 2, y + 2);
        }
    }

    // either row, col
    if(x < 15 && y > 3) {
        for(int i = 1; i <= 4; i++) {
            if(grid[x + i][y - i] != status) {
                break;
            }
            if(i == 4)
                return make_pair(x + 2, y - 2);
        }
    }
    return make_pair(-1, -1);
}

pair<int, int> searching(vector<vector<int>>& grid) {
    for(int x = 0; x < 19; x++) {
        for(int y = 0; y < 19; y++) {
            pair<int, int> temp;
            temp = checking(grid, x, y);

            if(temp.first != -1) {
                return temp;
            }
        }
    }

    return make_pair(-1, -1);
}


int main() {
    vector<vector<int>> grid(19, vector<int>(19, 0));

    for(auto& row : grid) {
        for(auto& var : row) {
            cin >> var;
        }
    }

    pair<int, int> coor = searching(grid);

    if(coor.first != -1) {
        int winner = grid[coor.first][coor.second];
        cout << winner << "\n" << coor.first + 1<< " " << coor.second + 1;
    }
    else {
        cout << 0;
    }

    return 0;
}