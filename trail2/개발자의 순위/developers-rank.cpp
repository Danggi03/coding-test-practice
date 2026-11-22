#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Input variable
    int k, n;
    cin >> k >> n;

    vector<vector<int>> match(k);
    int sequence = 0;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            int dev;
            cin >> dev;
            match[i].push_back(dev);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            int temp = 0;
            for(int league = 0; league < k; league++) {
                auto a = find(match[league].begin(), match[league].end(), i);
                auto b = find(match[league].begin(), match[league].end(), j);

                if(a > b)
                    temp++;
            }
            if(temp == k)
                sequence++;
        }
    }

    cout << sequence;
    return 0;
}