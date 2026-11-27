#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    int maxH = 0;
    vector<int> seq(n);
    for(auto& var: seq) {
        cin >> var;
    }

    sort(seq.begin(), seq.end());
        

    if(seq[0] >= n) {
        cout << n;
        return 0;
    }

    for(int h = 1; h <= n; h++) {
        int temp_l = l;
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(h <= count)
                break;
            if(h <= seq[i]) {
                count++;
            }
            else {
                int upgrade = seq[i] + 1;
                if(temp_l > 0 && h == upgrade) {
                    count++;
                    temp_l--;
                }
            }
        }

        if(h <= count) {
            maxH = max(maxH, h);
        }
        else {
            break;
        }
    }

    cout << maxH;
    return 0;
}