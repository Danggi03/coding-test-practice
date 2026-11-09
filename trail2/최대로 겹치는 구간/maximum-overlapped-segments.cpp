#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x, y;
    int offset = 100;
    int maxLine = 0;
    //test time
    cin >> n;
    vector<int> line(200 + 1); // 0 <= x <= 200

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        x += offset;
        y += offset;
        //color
        for(int l = x; l < y; l++) {
            line[l]++;
        }
    }

    for(int freq : line) {
        maxLine = max(maxLine, freq);
    }

    cout << maxLine;
    return 0;
}