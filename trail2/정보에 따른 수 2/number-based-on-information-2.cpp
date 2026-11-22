#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> N;
    vector<int> S;
    int special = 0;
    
    for(int i = 0; i < n; i++) {
        char direct;
        int pos;
        cin >> direct >> pos;

        if(direct == 'N') {
            N.push_back(pos);
        }
        else if(direct == 'S') {
            S.push_back(pos);
        }
    }

    for(int i = a; i <= b; i++) {
        int minS = 99999;
        int minN = 99999;

        // S
        for(int d = 0; d < S.size(); d++) {
            minS = min(minS, abs(i - S[d]));
        }

        // N
        for(int d = 0; d < N.size(); d++) {
            minN = min(minN, abs(i - N[d]));
        }

        if(minS <= minN)
            special++;
    }

    cout << special;
    return 0;
}