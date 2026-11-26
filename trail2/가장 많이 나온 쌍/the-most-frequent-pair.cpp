#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> coor(m);
    vector<bool> check(m, true);
    int maxC = 1;

    for(auto& var : coor) {
        cin >> var.first >> var.second;
    }

    for(int i = 0; i < m - 1; i++) {
        if(check[i] == false) continue;
        check[i] = false;
        int count = 1;
        for(int j = i + 1; j < m; j++) {
            if(check[j] && ((coor[i].first == coor[j].first && coor[i].second == coor[j].second) || (coor[i].first == coor[j].second && coor[i].second == coor[j].first))) {
                check[j] = false;
                count++;
            }
        }
        maxC = max(maxC, count);
    }

    cout << maxC;
    return 0;
}