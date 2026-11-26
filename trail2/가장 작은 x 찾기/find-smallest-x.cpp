#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> coor(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> coor[i].first >> coor[i].second;
    }

    for(int x = 1; x <= coor[n].second; x++) {
        int i = 1;
        for(; i <= n; i++) {
            if(coor[i].first > (1 << i) * x || (1 << i) * x > coor[i].second)
                break;
        }
        if(i == n + 1) {
            cout << x;
            return 0;
        }
    }
    cout << (2 << 2) * 3;
    return 0;
}