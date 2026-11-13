#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Input Variable
    int n;
    cin >> n;
    
    vector<int> basis(3);
    int count = 0;
    for(auto& var : basis) {
        cin >> var;
    }

    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= n; y++) {
            for(int z = 1; z <= n; z++) {
                if((abs(x - basis[0]) <= 2) || (abs(y - basis[1]) <= 2) || (abs(z - basis[2]) <= 2)) {
                    count++;
                }
            }
        }
    }

    cout << count;
    return 0;
}