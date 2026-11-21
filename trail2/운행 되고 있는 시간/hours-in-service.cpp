#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Input variable
    int n;
    cin >> n;
    
    vector<pair<int, int>> devtime(n);
    int maxT = 0;
    for(auto& var : devtime) {
        cin >> var.first >> var.second;
    }

    for(int skip = 0; skip < n; skip++) {
        vector<int> time(1001);
        int temp = 0;

        for(int i = 0; i < n; i++) {
            if (skip == i) continue;

            for(int t = devtime[i].first; t < devtime[i].second; t++) {
                time[t]++;
            }
        }
                    
        for(int i = 0; i < time.size(); i++) {
            if(time[i] >= 1) {
                temp++;
            }
        }

        maxT = max(maxT, temp);
    }

    cout << maxT;
    return 0;
}