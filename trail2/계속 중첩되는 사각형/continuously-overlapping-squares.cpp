#include <iostream>
#include <vector>

using namespace std;

void calculate (vector<vector<int>>& coor, int x1, int y1, int x2, int y2, int increase) {
    for(int x = x1; x < x2; x++) {
        for(int y = y1; y < y2; y++) {
            coor[x][y] = increase;
        }
    }
}

int main() {
    //input variable
    int n, x1, y1, x2, y2;
    vector<vector<int>> coordinate(201, vector<int>(201, 0));
    int offset = 100;
    
    int count = 0;

    //test case
    cin >> n;
    for(int freq = 1; freq <= n; freq++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if(freq % 2 == 1) { // odd -> 1st red square
            calculate(coordinate, x1 + offset, y1 + offset, x2 + offset, y2 + offset, 0);
        }
        else { // even -> 2nd blue square
            calculate(coordinate, x1 + offset, y1 + offset, x2 + offset, y2 + offset, 1);
        }
    }

    for(auto& row : coordinate) {
        for(auto& var : row) {
            if(var == 1) {
                count++;
            }
        }
    }

    cout << count;
    return 0;
}