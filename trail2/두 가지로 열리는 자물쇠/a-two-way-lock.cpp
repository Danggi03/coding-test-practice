#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool ispossible(const int& n, const int& x, const int& y, const int& z, const vector<int>& c) {
    int diff = abs(c[0] - x);
    diff = min(diff, n - diff);

    if(diff <= 2) {
        diff = abs(c[1] - y);
        diff = min(diff, n - diff);
        if(diff <= 2) {
            diff = abs(c[2] - z);
            diff = min(diff, n - diff);
            if(diff <= 2) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    // Input Variable
    int n;
    cin >> n;


    int find = 0;
    vector<int> c1(3);
    for(auto& var : c1) {
        cin >> var;
    }
    vector<int> c2(3);
    for(auto& var : c2) {
        cin >> var;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(ispossible(n, i, j, k, c1) || ispossible(n, i, j, k, c2))
                    find++;
            }
        }
    }

    cout << find;
    return 0;
}