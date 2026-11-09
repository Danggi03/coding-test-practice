#include <iostream>
#include <vector>
#include <algorithm>
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
    int x1, y1, x2, y2;
    int offset = 1000;
    int maxX = 0, maxY = 0, minX = 2001, minY = 2001;
    vector<vector<int>> coordinate(2001, vector<int>(2001, 0));

    int extent = 0;
    bool except = true;

    //first square
    cin >> x1 >> y1 >> x2 >> y2;
    calculate(coordinate, x1 + offset, y1 + offset, x2 + offset, y2 + offset, 1);
    //second square
    cin >> x1 >> y1 >> x2 >> y2;
    calculate(coordinate, x1 + offset, y1 + offset, x2 + offset, y2 + offset, 0);

    for(int x = 0; x < 2001; x++) {
        for(int y = 0; y < 2001; y++) {
            if(coordinate[x][y] == 1) {
                maxX = max(maxX, x);
                maxY = max(maxY, y);
                minX = min(minX, x);
                minY = min(minY, y);
                except = false;
            }
        }
    }

    extent = (maxX - minX + 1) * (maxY - minY + 1);
    
    if(except)
        cout << 0;
    else
        cout << extent;
    
    return 0;
}