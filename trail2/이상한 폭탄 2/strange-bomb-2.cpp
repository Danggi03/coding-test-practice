#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Input Variable
    int n, k;
    cin >> n >> k;
    
    vector<int> bomb(n);
    int maxB = -1;

    for(auto& var : bomb) {
        cin >> var;
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; (j <= i + k) && (j != bomb.size()); j++) {
            if(bomb[i] == bomb[j]) {
                maxB = max(maxB, bomb[i]);
            }
        }
    }

    cout << maxB;
    return 0;
}