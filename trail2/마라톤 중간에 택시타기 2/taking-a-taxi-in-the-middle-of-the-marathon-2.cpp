#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// |x1 - x2| + |y1 - y2|
int md(const int& x1, const int& y1, const int& x2, const int& y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
int main() {
    // input variable
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    int distance = 99999999;

    for(auto& var: arr) {
        int x, y;
        cin >> x >> y;
        var = make_pair(x, y);
    }

    for(int skip = 1; skip < n - 1; skip++) {
        int temp = 0;
        for(int i = 0; i < n - 1; i++) {
            //skip
            if(i + 1 == skip) {
                temp += md(arr[i].first, arr[i].second, arr[i + 2].first, arr[i + 2].second);
                i++;
            }
            else {
                temp += md(arr[i].first, arr[i].second, arr[i + 1].first, arr[i + 1].second);
            }
        }
        distance = min(distance, temp);
    }

    cout << distance;
    return 0;
}