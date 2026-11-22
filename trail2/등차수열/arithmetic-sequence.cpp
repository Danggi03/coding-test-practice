#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> seq(n);
    int result = 0;
    
    int minK = 999999;
    int maxK = -1;
    for(auto& var : seq) {
        cin >> var;
        minK = min(minK, var);
        maxK = max(maxK, var);
    }

    for(int k = minK + 1; k < maxK; k++) {
        int temp = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(k - seq[i] == seq[j] - k) {
                    temp++;
                }
            }
        }
        result = max(result, temp);
    }

    cout << result;
    return 0;
}