#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // input variable
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int maxValue = 0;

    for(auto& row : matrix) {
        for(auto& var : row) {
            cin >> var;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 2; j++) {
            int x = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2];
            maxValue = max(maxValue, x);
        }
    }

    cout << maxValue;
    return 0;
}