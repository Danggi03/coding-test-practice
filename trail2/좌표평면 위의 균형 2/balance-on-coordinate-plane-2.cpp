#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // input variable
    int n;
    cin >> n;

    vector<pair<int, int>> coor(n);

    for(auto& var : coor) {
        cin >> var.first >> var.second;
    }
    int max_val = 0;
    int minV = 999999;
    for(int limit_x = 0; limit_x <= 101; limit_x += 2) {
        for(int limit_y = 0; limit_y <= 101; limit_y += 2) {
            int square_1 = 0;
            int square_2 = 0;
            int square_3 = 0;
            int square_4 = 0;


            for(int i = 0; i < n; i++) {
                // square_1
                if(coor[i].first > limit_x && coor[i].second > limit_y) {
                    square_1++;
                }
                // square_2
                else if(coor[i].first > limit_x && coor[i].second < limit_y) {
                    square_2++;
                }
                // square_3
                else if(coor[i].first < limit_x && coor[i].second < limit_y) {
                    square_3++;
                }
                // square_4
                else if(coor[i].first < limit_x && coor[i].second > limit_y) {
                    square_4++;
                }
            }

            max_val = max({square_1, square_2, square_3, square_4});
            minV = min(max_val, minV);
        }
    }

    cout << minV;
    return 0;
}