#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Input variable
    int n;
    cin >> n;
    
    vector<pair<int, int>> matrix(n);
    int result = 0;

    for(auto& var : matrix) {
        cin >> var.first >> var.second;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            int xsc = 0; // x same count
            int ysc = 0; // y same count

            if(matrix[i].first == matrix[j].first)
                xsc++;
            if(matrix[i].second == matrix[j].second)
                ysc++;
            
            for(int k = 0; k < n; k++) {
                if(i == k || j == k) continue;

                int tempxsc = 0;
                int tempysc = 0;

                if(matrix[i].first == matrix[k].first || matrix[j].first == matrix[k].first)
                    tempxsc++;
                if(matrix[i].second == matrix[k].second || matrix[j].second == matrix[k].second)
                    tempysc++;
                
                if((tempxsc + xsc == 1) && (tempysc + ysc == 1)) {
                    result = max(result, abs(((matrix[i].first * matrix[j].second) + (matrix[j].first * matrix[k].second) + (matrix[k].first * matrix[i].second)) - 
                    ((matrix[j].first * matrix[i].second) + (matrix[k].first * matrix[j].second) + (matrix[i].first * matrix[k].second))));
                }
            }
        }
    }

    cout << result;
    return 0;
}