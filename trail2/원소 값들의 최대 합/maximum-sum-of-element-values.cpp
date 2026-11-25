#include <iostream>
#include <vector>

using namespace std;

int main() {
    // INPUT variable
    int n, m;
    cin >> n >> m;

    vector<int> seq(n + 1);
    int maxV = 0;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        seq[i] = x;
    }

    for(int i = 1; i <= n; i++) {
        int count = m - 1;
        int sum = seq[i];
        int j = seq[i];
        while(count-- > 0) {
            sum += seq[j];
            j = seq[j];
        }

        maxV = max(maxV, sum);
    }

    cout << maxV;
    return 0;
}