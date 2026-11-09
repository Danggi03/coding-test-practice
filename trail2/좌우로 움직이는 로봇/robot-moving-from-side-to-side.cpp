#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // input variable
    int n, m;
    cin >> n >> m;

    // result variable
    vector<int> rAtime(2e6 + 1);
    vector<int> rBtime(2e6 + 1);
    int coordinateA = 0;
    int coordinateB = 0;
    int timeA = 0;
    int timeB = 0;

    int var = 0;
    
    // input values
    for(int i = 0; i < n; i++) {
        int x;
        char direct;
        cin >> x >> direct;

        while(x--) {
            timeA++;
            if(direct == 'R') {
                rAtime[timeA] = ++coordinateA;
            }
            else
                rAtime[timeA] = --coordinateA;
        }
    }

    for(int i = 0; i < m; i++) {
        int x;
        char direct;
        cin >> x >> direct;

        while(x--) {
            timeB++;
            if(direct == 'R') {
                rBtime[timeB] = ++coordinateB;
            }
            else
                rBtime[timeB] = --coordinateB;
        }
    }

    if(timeA > timeB) {
        while(timeB++ < timeA) {
            rBtime[timeB] = coordinateB;
        }
    }
    else if(timeB > timeA) {
        while(timeA++ < timeB) {
            rAtime[timeA] = coordinateA;
        }
    }

    for(int i = 1; i < timeA; i++) {
        if(rAtime[i] == rBtime[i]) {
            if(rAtime[i - 1] != rBtime[i - 1])
                var++;
        }
    }

    cout << var;

    return 0;
}