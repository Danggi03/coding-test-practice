#include <iostream>
#include <vector>
using namespace std;

int main() {
    //input variable
    int n, x1, y1;
    vector<vector<int>> coordinate(201, vector<int>(201, 0));
    
    int count = 0;

    //test case
    cin >> n;
    for(int freq = 0; freq < n; freq++) {
        cin >> x1 >> y1;
        x1 += 100;
        y1 += 100;
        for(int x = x1; x < x1 + 8; x++) {
            for(int y = y1; y < y1 + 8; y++) {
                if(coordinate[x][y] == 0 ) {
                    coordinate[x][y]++;
                }
            }
        }
    }

    for(auto& row : coordinate) {
        for(auto& val : row) {
            if(val == 1)
                count++;
        }
    }

    cout << count;
    return 0;
}