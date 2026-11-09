#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INT_MAX 1000000

void running(vector<int>& arr, const int& count) {
    int time = 0;
    for(int i = 0; i < count; i++) {
        pair<int, int> x; // speed, time
        cin >> x.first >> x.second;
        while(x.second--) {
            time++;
            arr[time] += arr[time - 1] + x.first;
        } 
    }
    arr[++time] = INT_MAX;
}
int main() {
    // input variable
    int n, m;
    cin >> n >> m;

    // result variable
    vector<int> a(1e6);
    vector<int> b(1e6);
    vector<int> leader(1e6);
    int winlevel = 0;
    
    running(a, n);
    running(b, m);

    for(int time = 0; a[time] != INT_MAX; time++) {
        if(a[time] > b[time]) // a win
            leader[time] = 1;
        else if(b[time] > a[time]) // b win
            leader[time] = 2;
        else
            leader[time] = leader[time - 1];
    }

    for(int i = 1; a[i] != INT_MAX; i++) {
        if(leader[i] != leader[i - 1]) {
            winlevel++;
        }
    }
    --winlevel == -1 ? cout << 0 : cout << winlevel;
    return 0;
}