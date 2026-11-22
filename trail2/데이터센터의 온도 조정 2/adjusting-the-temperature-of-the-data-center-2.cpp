#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int data_center(const vector<pair<int,int>>& data, int freq, int number, const int& c, const int& g, const int& h) {
    if(number < data[freq].first)
        return c;
    else if(number >= data[freq].first && number <= data[freq].second)
        return g;
    else if(number > data[freq].second)
        return h;
}

int main() {
    // INPUT DATA
    int n, c, g, h;
    cin >> n >> c >> g >> h;
    
    int minTA = 9999;
    int maxTB = -9999;

    vector<pair<int, int>> data(n);
    int total = 0;

    for(auto& var : data) {
        cin >> var.first >> var.second;

        minTA = min(minTA, var.first);
        maxTB = max(maxTB, var.second);
    }


    if(minTA == 0) {
        int zero = 0;
        for(int i = 0; i < n; i++) {
            zero += data_center(data, i, -1, c, g, h);
        }
        total = max(total, zero);

        for(int temp = minTA; temp <= maxTB + 1; temp++) {
            int tmp = 0;
            for(int i = 0; i < n; i++) {
                tmp += data_center(data, i, temp, c, g, h);
            }
            total = max(total, tmp);
        }
    }
    else {
        for(int temp = minTA - 1; temp <= maxTB + 1; temp++) {
            int tmp = 0;
            for(int i = 0; i < n; i++) {
                tmp += data_center(data, i, temp, c, g, h);
            }
            total = max(total, tmp);
        }
    }

    cout << total;
    return 0;
}