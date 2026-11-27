#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int maxB = 0;
    vector<int> bomb(n + 1);
    unordered_map<int, int> last_idx;
    unordered_map<int, int> bomb_idx;
    vector<bool> overrap(n + 1, true);

    // 1 - based
    for(int i = 1; i <= n; i++) {
        cin >> bomb[i];
    }

    for(int i = 1; i <= n; i++) {
        int b = bomb[i];
        if(last_idx[b] == 0) {
            last_idx[b] = i;
            continue;
        }

        if(i - last_idx[b] <= k) {

            if(overrap[i] && overrap[last_idx[b]]) {
                bomb_idx[b] += 2;
                overrap[i] = false;
                overrap[last_idx[b]] = false;
                last_idx[b] = i;
            }
            else if(overrap[i] && !overrap[last_idx[b]]) {
                bomb_idx[b]++;
                overrap[i] = false;
                last_idx[b] = i;
            }
        }
        else {
            last_idx[b] = i;
        }
    }

    int temp = 0;
    for(const auto&[idx, count] : bomb_idx) {
        // cout << idx << " || " << count << endl;
        if(count > temp) {
            temp = count;
            maxB = idx;
        }
        else if(count == temp) {
            maxB = max(maxB, idx);
        }
    }

    cout << maxB;    
    
    return 0;
}