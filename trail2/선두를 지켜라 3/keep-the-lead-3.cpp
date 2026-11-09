#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_INT 9999999
using namespace std;

void running(vector<int>& human, const int& count) {
        int timeA = 0;
        for(int i = 0; i < count; i++) {
        int u, t;
        cin >> u >> t;
        
        while(t--) {
            timeA++;
            human[timeA] = human[timeA - 1] + u;
        }
    }
    human[++timeA] = MAX_INT;
}

int main() {
    // input variable
    int n, m;
    cin >> n >> m;

    vector<int> a(1e6);
    vector<int> b(1e6);
    vector<int> leader(1e6);
    int var = 0;

    // init
    running(a, n);
    running(b, m);

    for(int i = 1; a[i] != MAX_INT; i++) {
        // a leader = 1
        if(a[i] > b[i]) {
            leader[i] = 1;
        }
        // b leader = 2
        else if(a[i] < b[i]) {
            leader[i] = 2;
        }
        // either a and b leader = 2
        else {
            leader[i] = 3;
        }
    }

    for(int i = 1; a[i] != MAX_INT; i++) {
        if(leader[i] != leader[i - 1]) {
            var++;
        }
    }
    cout << var;
    return 0;
}