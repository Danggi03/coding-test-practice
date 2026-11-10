#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // input variable
    int n;
    cin >> n;

    vector<vector<int>> matrix (n, vector<int>(n, 0));
    int result = -1;
    for(auto& row : matrix) {
        for(auto& var : row) {
            cin >> var;
        }
    }


    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n - 2; y++) {
            int coinA = matrix[x][y] + matrix[x][y + 1] + matrix[x][y + 2];
            if(n >= 6 && y < n - 5) {
                for(int z = y + 3; z < n - 2; z++) {
                    int coinB = matrix[x][z] + matrix[x][z + 1] + matrix[x][z + 2];
                    result = max(coinA + coinB, result);
                }
            }
            for(int i = x + 1; i < n; i++) {
                for(int j = 0; j < n - 2; j++) {
                    int coinB = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2];
                    result = max(coinA + coinB, result);
                }
            }
        }
    }
    cout << result;
    return 0;
}
