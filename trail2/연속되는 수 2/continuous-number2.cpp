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
        int num;
        cin >> num;
        arr[i] = num;
    }

    for (int i = 0 ; i < arr.size(); i++) {
        if(i == 0 || arr[i] != arr[i - 1]) {
            temp = 0;
        }
        temp++;
        count = max(count, temp);
    }

    cout << count;
    return 0;
}