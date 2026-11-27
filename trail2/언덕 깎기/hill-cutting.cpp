#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> mountain(n);
    int min_cost = 2100000000;

    for(auto& var : mountain) {
        cin >> var;
    }

    for(int minV = 0; minV <= 83; minV++) {
        int temp_cost = 0; 
        for(int i = 0; i < n; i++) {
            if(minV <= mountain[i] && mountain[i] <= minV + 17)
                continue;

            if(mountain[i] < minV) {
                int def = minV - mountain[i];
                temp_cost += def * def;
            }
            else if(mountain[i] > minV + 17) {
                int def = mountain[i] - (minV + 17);
                temp_cost += def * def;
            }
        }

        min_cost = min(min_cost, temp_cost);
    }

    cout << min_cost;
    return 0;
}