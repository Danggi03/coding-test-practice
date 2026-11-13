#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Input variable
    int n, h, t;
    cin >> n >> h >> t;

    vector<int> arr(n);
    int minV = 9999999;

    for(auto& var : arr) {
        cin >> var;
    }

    int sliding = 0;
    for(int i = 0; i < n; i++) {
        sliding += abs(h - arr[i]);

        if(i >= t - 1) {
            minV = min(minV, sliding);
            sliding -= abs(h - arr[i - t + 1]); 
        }
    }

    cout << minV;


    return 0;
}