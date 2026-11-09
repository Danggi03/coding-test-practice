#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Input variable
    int n;
    cin >> n;
    vector<int> arr(n);
    int minCount = 99999999;

    for(auto& var : arr) {
        cin >> var;
    }

    for(int i = 0; i < n; i++) {
        int index = i;
        int temp = 0;
        int count = 0;

        while(count < n) {
            if(index == n)
                index = 0;

            temp += arr[index] * count;
            count++;
            index++;
        }
        count = 0;
        minCount = min(temp, minCount);
    }

    cout << minCount;
    return 0;
}