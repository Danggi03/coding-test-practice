#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Input Variable
    int n, k;
    cin >> n >> k;
    
    vector<int> candy(101);
    int maxV = -1;

    for(int i = 0; i < n; i++) {
        int a, x;
        cin >> a >> x;
        
        candy[x] += a;
    }

    int sliding = 0;
    if(k < 50) {
        for(int i = 0; i < candy.size(); i++) {
            sliding += candy[i];
            
            // sliding window
            if(i >= k * 2) {
                maxV = max(sliding, maxV);
                sliding -= candy[i - (k * 2)];
            }
        }
    }
    else {
        maxV = 0;
        for(int i = 0; i < candy.size(); i++) {
            maxV += candy[i]; 
        }
    }
    
    
    cout << maxV;
    return 0;
}