#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //input variable
    int n, t;
    cin >> n >> t;

    vector<int> arr(n);
    int temp = 0;
    int count = 0;

    //test case
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    //core
    for(int i = 0; i < n; i++) {
        if(arr[i] <= t) {
            temp = 0;
        }
        else {
            temp++;
        }

        count = max(temp, count);
    }

    cout << count;
    return 0;
}