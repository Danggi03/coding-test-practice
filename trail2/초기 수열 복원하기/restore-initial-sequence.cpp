#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> sum_arr(n - 1);
    for(auto& var: sum_arr) {
        cin >> var;
    }

    vector<int> seq(n);
    unordered_set<int> overrap;
    // init
    seq[0] = 1;

    for(int i = 0; i < n - 1; i++) {
        int x = seq[i];
        overrap.insert(x);
        int y;
        if(x < sum_arr[i]) {
            y = sum_arr[i] - x;
        }
        else if(y == 0) {
            i = 0;
            continue;
        }
        
        if(x != y && x != sum_arr[i] && y != sum_arr[i] && overrap.find(y) == overrap.end()) {
            seq[i + 1] = y;
            overrap.insert(y);
        }
        else {
            if(i >= 1)
                i = 0;
            seq[i]++;
            i--;
            overrap = unordered_set<int>();
        }
    }

    for(auto& var : seq) {
        cout << var << " ";
    }

    
    return 0;
}