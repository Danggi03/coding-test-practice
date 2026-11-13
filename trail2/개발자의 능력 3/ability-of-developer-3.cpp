#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    // input variable

    vector<int> developer(6);
    int sum = 0;
    int minV = 99999999;

    for(auto& var : developer) {
        cin >> var;
        sum += var;
    }
    for(int i = 0; i < developer.size() - 2; i++) {
        for(int j = i + 1; j < developer.size() - 1; j++) {
            int temp = 0;
            int secteam = 0;
            int secmin = 0;
            for(int k = j + 1; k < developer.size(); k++) {
                temp = developer[i] + developer[j] + developer[k];
                secteam = abs(sum - temp);
                secmin = abs(secteam - temp);
                minV = min(minV, secmin);
            }
        }
    }

    cout << minV;
    return 0;
}