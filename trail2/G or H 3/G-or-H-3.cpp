#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Input variable
    int n, k;
    cin >> n >> k;

    vector<char> arr(10001);
    for(int i = 0; i < n; i++) {
        int x;
        char point;
        cin >> x >> point;

        arr[x] = point;
    }

    int maxV = -1;

    for(int i = 0; i <= arr.size() - k + 1; i++) {
        int temp = 0;
        for(int x = i; x <= i + k; x++) {
            if(arr[x] == 'G')
                temp += 1;
            else if(arr[x] == 'H')
                temp += 2;
        }
        maxV = max(temp, maxV);
    }

    cout << maxV;
    return 0;
}