#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x, y;
    int maxLine = 0;
    vector<int> lines(101);
    
    //test case
    cin >> n;

    for(int freq = 0; freq < n; freq++) {
        cin >> x >> y;
        for(int i = x; i <= y; i++) {
            lines[i]++;
        }
    }

    for(int freq : lines) {
        maxLine = max(maxLine, freq);
    }

    cout << maxLine;
    return 0;
}