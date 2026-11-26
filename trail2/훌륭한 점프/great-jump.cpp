#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    int maxN = 0;

    for(auto& var: vec) {
        cin >> var;
        maxN = max(maxN, var);
    }
    int a = max(vec[0], vec[n-1]);
    for(; a <= maxN; a++) {
        int temp_k = 0;
        int i = 1;

        while(temp_k < k && i < n) {
            if(vec[i] > a) {
                temp_k++;
                i++;
            }
            else {
                temp_k = 0;
                i++;
            }
        }

        if(temp_k != k) {
            break;
        }
    }

    cout << a;
    return 0;
}