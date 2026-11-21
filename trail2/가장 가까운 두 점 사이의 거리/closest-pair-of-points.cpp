#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    // Input variable
    int n;
    cin >> n;
    
    vector<pair<int, int>> matrix(n);
    int minV = 2100000000;

    for(auto& var : matrix) {
        cin >> var.first >> var.second;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int x = pow((matrix[i].first - matrix[j].first), 2);
            int y = pow((matrix[i].second - matrix[j].second), 2);

            minV = min(minV, x + y);
        }
    }

    cout << minV;
    return 0;
}