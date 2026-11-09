#include <iostream>
#include <vector>
using namespace std;

int main() {
    // input variable
    int n;
    cin >> n;
    
    vector<int> arr(n);
    int count = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n - 2; i++) {
        int index = i;
        for(int j = i + 1; j < n - 1; j++) {
            //skip
            if(arr[i] > arr[j])
                continue;
            
            for(int k = j + 1; k < n; k++) {
                //skip
                if(arr[j] > arr[k])
                    continue;

                count++;
            }
            
        }
    }

    cout << count;
    return 0;
}