#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // input variable
    int n;
    cin >> n;

    vector<int> arr(n);
    int result = 0;
    
    for(auto& var : arr) {
        cin >> var;
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(abs(i - j) >= 2) {
                result = max(arr[i] + arr[j], result);
            }
        }
    }

    cout << result;
    return 0;
}