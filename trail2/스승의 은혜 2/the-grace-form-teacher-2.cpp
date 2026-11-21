#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // INPUT variable
    int n, b;
    cin >> n >> b;

    vector<int> gift(n);
    int result = 0;

    for(auto& var : gift) {
        cin >> var;
    }

    sort(gift.begin(), gift.end());

    for(int i = 0; i < n; i++) {
        b -= gift[i];

        if(b < 0 && b + (gift[i] / 2) < 0)
            break;
            
        result++;
    }
    cout << result;
    return 0;
}