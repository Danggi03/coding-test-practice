#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int size, Q, maxV = 0;
    cin >> size >> Q;
    
    vector<int> block(size + 1);
    
    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        for(int x = a; x <= b; x++) {
            block[x]++;
        }
    }

    for(int freq : block) {
        maxV = max(maxV, freq);
    }

    cout << maxV;
    return 0;
}