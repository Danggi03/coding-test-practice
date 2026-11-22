#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // input variable
    int n;
    cin >> n;

    vector<int> ice(n);
    int minI = 999999;
    int maxI = -1;
    int count = 1;

    for(auto& var : ice) {
        cin >> var;
        minI = min(minI, var);
        maxI = max(maxI, var);
    }

    for(int s = minI; s < maxI; s++) {
        int temp = 0;
        
        //init
        if(ice[0] > s)
            temp++;

        for(int i = 1; i < n; i++) {
            if((ice[i - 1] <= s) && (ice[i] > s))
                temp++;
        }

        count = max(count, temp);
    }

    cout << count;
    return 0;
}