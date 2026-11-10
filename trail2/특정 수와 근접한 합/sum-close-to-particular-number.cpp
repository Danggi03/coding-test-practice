#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // Input variable
    int n, s;
    cin >> n >> s;;
    vector<int> arr(n);
    int minV = 99999999;

    for(auto& var : arr) {
        cin >> var;
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int t = 0;
            int absT = 0;
            for(int freq = 0; freq < n; freq++) {
                if(freq == i || freq == j)
                    continue;
                t += arr[freq];
            }

            absT = abs(t - s);
            minV = min(absT, minV);
        }
    }

    cout << minV;
    return 0;
}