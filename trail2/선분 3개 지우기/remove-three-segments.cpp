#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> coor(n);
    int result = 0;

    for(auto& var : coor) {
        cin >> var.first >> var.second;
    }

    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                vector<int> matrix(101);
                for(int l = 0; l < n; l++) {
                    if(l == k || l == j || l == i) continue;

                    for(int x = coor[l].first; x <= coor[l].second; x++) {
                        matrix[x]++;
                    }
                }
                bool is_true = true;
                for(int l = 0; l < matrix.size(); l++) {
                    if(matrix[l] >= 2) {
                        is_true = false;
                        break;
                    }
                }
                if(is_true) result++;
            }
        }
    }

    cout << result;
    return 0;
}