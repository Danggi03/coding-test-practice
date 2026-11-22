#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int maxV = 0;
    for(int i = x; i <= y; i++) {
        // 10000
        int d1 = (i / 10000) % 10;
        // 1000
        int d2 = (i / 1000) % 10;
        // 100
        int d3 = (i / 100) % 10;
        // 10
        int d4 = (i / 10) % 10;
        // 1
        int d5 = i % 10;

        maxV = max(maxV, d1 + d2 + d3 + d4 + d5);
    }

    cout << maxV;
    
    return 0;
}