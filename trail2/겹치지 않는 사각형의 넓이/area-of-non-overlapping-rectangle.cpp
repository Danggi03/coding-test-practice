#include <iostream>
#include <vector>
using namespace std;

void calculate(vector<vector<int>>& coor, int x1, int y1, int x2, int y2, int increase) {
    for(int x = x1; x < x2; x++) {
        for(int y = y1; y < y2; y++) {
            coor[x][y] = increase;
        }
    }
}
int main() {
    //input variable
    int x1, x2, y1, y2;
    vector<vector<int>> coordinate(2001, vector<int>(2001, 0));
    
    int count = 0;

    //test case (a, b)
    for(int freq = 0; freq < 2; freq++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1000;
        y1 += 1000;
        x2 += 1000;
        y2 += 1000;
        calculate(coordinate, x1, y1, x2, y2, 2);
    }
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 1000;
    y1 += 1000;
    x2 += 1000;
    y2 += 1000;
    calculate(coordinate, x1, y1, x2, y2, 1);

    for(auto& row : coordinate) {
        for(auto& var : row) {
            if (var == 2) 
                count++;
        }
    }

    cout << count;
    return 0;
}