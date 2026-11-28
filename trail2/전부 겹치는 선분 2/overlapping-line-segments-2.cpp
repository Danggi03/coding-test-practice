#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> coor(n);

    for(auto& var: coor) {
        cin >> var.first >> var.second;
    }

    for(int del = 0; del < n; del++) {
        vector<int> temp(101);
        for(int i = 0; i < n; i++) {
            if(del == i) continue;

            for(int x = coor[i].first; x <= coor[i].second; x++) {
                temp[x]++;
            }
        }

        for(auto& var: temp) {
            if(var == n - 1) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
    return 0;
}