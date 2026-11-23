#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // input variable

    int n;
    cin >> n;

    vector<int> seq(n);
    int minV = 21000000;

    for(auto& var: seq) {
        cin >> var;
    }

    for(int multiple = 0; multiple < n; multiple++) {
        // 2 to multiple
        seq[multiple] *= 2;

        for(int remove = 0; remove < n; remove++) {
            vector<int> new_seq(n - 1);
            int new_seq_idx = 0;
            int temp = 0;
            for(int i = 0; i < n; i++, new_seq_idx++) {
                if (i == remove) {
                    new_seq_idx--;
                    continue;
                }
                new_seq[new_seq_idx] = seq[i];
            }

            for(int i = 1; i < new_seq.size(); i++) {
                temp += abs(new_seq[i - 1] - new_seq[i]);
            }
            minV = min(minV, temp);
        }

        //recover
        seq[multiple] /= 2;
    }

    cout << minV;
    
    return 0;
}