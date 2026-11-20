#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_INT 2100000000
#define MIN_INT -2100000000

using namespace std;

int main() {
    // input variable
    int n;
    cin >> n;

    int size = MAX_INT;
    vector<pair<int, int>> matrix(n);
    
    for(auto& var : matrix) {
        pair<int, int> coex;
        cin >> coex.first >> coex.second;
        var = coex;
    }

    for(int skip = 0; skip < n; skip++) {
        int max_x = MIN_INT;
        int min_x = MAX_INT;
        int max_y = MIN_INT;
        int min_y = MAX_INT;
        for(int i = 0; i < n; i++) {
            if(skip == i) continue;
            max_x = max(max_x, abs(matrix[i].first));
            min_x = min(min_x, abs(matrix[i].first));
            max_y = max(max_y, abs(matrix[i].second));
            min_y = min(min_y, abs(matrix[i].second));
        }
        size = min(size, (max_x - min_x) * (max_y - min_y));
    }

    cout << size;
    return 0;
}