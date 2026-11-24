#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> coor(n);

    for(auto& var : coor) {
        cin >> var.first >> var.second;
    }

    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= 10; j++) {
            for(int k = 0; k <= 10; k++) {
                
                // 해당 좌표의 방향 확인 경우의 수
                for(int mask = 0; mask < (1 << 3); mask++) {
                    bool covered = true;
                    // 해당 방향에서 모든 점들에 대해 확인
                    for(int p = 0; p < n; p++) {
                        int line1 = mask & (1 << 0) ? coor[p].second : coor[p].first;
                        int line2 = mask & (1 << 1) ? coor[p].second : coor[p].first;
                        int line3 = mask & (1 << 2) ? coor[p].second : coor[p].first;

                        if(line1 != i && line2 != j && line3 != k) {
                            covered = false;
                            break;
                        }
                    }

                    if(covered) {
                        cout << 1;
                        return 0;
                    }
                }
            }
        }
    }

    cout << 0;
    return 0;
}