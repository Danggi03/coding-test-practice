#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n;
    str.reserve(n);
    cin >> str;

    vector<int> seated_arr;
    int left_length = 0;
    int right_length = 0;

    for(int i = 0; i < n; i++) {
        if(str[i] == '1')
            seated_arr.push_back(i);
    }

    if(seated_arr.size() > 0) {
        int min_L = 99999;
        int best_one;
        int best_all;

        // 최소 거리
        for(int i = 0; i < seated_arr.size() - 1; i++) {
            min_L = min(min_L, abs(seated_arr[i] - seated_arr[i + 1])); 
        }
        
        // 서로 다른 구간에 한 명씩
        vector<int> one;
        if(seated_arr[0] != 0) {
            one.push_back(seated_arr[0]);
        }
        if(seated_arr[seated_arr.size() - 1] != n - 1) {
            one.push_back(n - seated_arr[seated_arr.size() - 1] - 1);
        }
        for(int i = 0; i < seated_arr.size() - 1; i++) {
            int gap = abs(seated_arr[i] - seated_arr[i + 1]);
            one.push_back(gap / 2);
        }
        sort(one.rbegin(), one.rend());

        best_one = 0;
        if(one.size() > 1) {
            best_one = one[1];
        }

        // 같은 구간에 몰아서 2명
        int together = 0;
        if(seated_arr[0] >= 2) {
            together = max(together, seated_arr[0] / 2);
        }
        if(seated_arr[seated_arr.size() - 1] <= n - 2) {
            together = max(together, (n - seated_arr[seated_arr.size() - 1] - 1) / 2);
        }
        for(int i = 0; i < seated_arr.size() - 1; i++) {
            int gap = abs(seated_arr[i] - seated_arr[i + 1]);
            together = max(together, (gap / 3));
        }

        cout << min(min_L, max(best_one, together));
        return 0;
    }
    else {
        cout << n - 1;
        return 0;
    }
}