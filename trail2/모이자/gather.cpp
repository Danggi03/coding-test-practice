#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define INT_MAX 9999999

int main() {
    // input variable
    int n;
    cin >> n;

    vector<int> arr(n);
    int result = 0;
    int minValue = INT_MAX;

    for(auto& var : arr) {
        cin >> var;
    }

    for(int i = 0; i < arr.size(); i++) {
        int temp = 0;
        for(int x = 0; x < arr.size(); x++) {
            temp += abs((x - i)) * arr[x];
        }
        minValue = min(minValue, temp);
    }
    cout << minValue;
    
    return 0;
}