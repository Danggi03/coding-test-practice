#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Input variable
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    int maxV = -1;

    for(auto& var : arr) {
        cin >> var;
    }

    for(int i = 0; i <= n - k; i++) {
        int temp = 0;
        for(int x = i; x < i + k; x++) {
            temp += arr[x];
        }
        maxV = max(temp, maxV);
    }

    cout << maxV;
    return 0;
}