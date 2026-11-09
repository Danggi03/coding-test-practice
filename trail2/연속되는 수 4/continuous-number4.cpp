#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //input variable
    int n;
    cin >> n;

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
        if(i == 0 || arr[i] <= arr[i - 1]) {
            temp = 0;
        }
        temp++;
        count = max(temp, count);
    }

    cout << count;
    return 0;
}