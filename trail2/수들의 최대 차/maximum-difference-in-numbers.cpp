#include <iostream>
#include <vector>

using namespace std;

int main() {
    // input variable
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    int maxN = 0;
    int maxV = 0;

    for(auto& var: vec) {
        cin >> var;
        maxN = max(maxN, var);
    }

    if(k < maxN) {
        for(int minV = 0; minV <= maxN - k; minV++) {
            int temp = 0;
            for (int i = 0; i < n; i++) {
                if(minV <= vec[i] && vec[i] <= minV + k)
                    temp++;
            }
            maxV = max(maxV, temp);
        }
    }
    else {
        cout << n;
        return 0;
    }

    cout << maxV;
    return 0;
}