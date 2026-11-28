#include <iostream>
#include <vector>
using namespace std;

int main() {
    // input variable
    int n, k;
    cin >> n >> k;

    vector<int> seq(n);
    int min_a = 99999;
    int max_a = 0;
    int cost = 210000000;

    for(auto& var: seq) {
        cin >> var;
        min_a = min(min_a, var);
        max_a = max(max_a, var);
    }
    
    for(int a = min_a; a <= max_a; a++) {
        int temp_cost = 0;
        for(int i = 0; i < n; i++) {
            if(a <= seq[i] && seq[i] <= a + k)  continue;
            else if(a > seq[i]) {
                temp_cost += (a - seq[i]);
            }
            else if(a + k < seq[i]) {
                temp_cost += seq[i] - (a + k);
            }
        }
        cost = min(cost, temp_cost);
    }

    cout << cost;

    return 0;
}