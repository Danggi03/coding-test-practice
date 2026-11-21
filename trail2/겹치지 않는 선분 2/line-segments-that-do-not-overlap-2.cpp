#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Input variable
    int n;
    cin >> n;

    vector<pair<int, int>> matrix(n);
    vector<bool> is_check(n, false);
    int result = 0;

    for(auto& var : matrix) {
        cin >> var.first >> var.second;
    }

    sort(matrix.begin(), matrix.end());

    int max_x2 = -2e9;
    for(int i = 0; i < n; i++) {
        if(matrix[i].second < max_x2)
            is_check[i] = true;
        else
            max_x2 = matrix[i].second;
    }

    int min_x2 = 2e9;
    for(int i = n - 1; i >= 0; i--) {
        if(matrix[i].second > min_x2)
            is_check[i] = true;
        else
            min_x2 = matrix[i].second;
    }

    for(bool var : is_check) {
        if(!var) result++;
    }

    cout << result;
    return 0;
}