#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iscarry(int a, int b) {
    int realA = a;
    int realB = b;
    int oneA = 0;
    int oneB = 0;

    while(a > 0 && b > 0) {
        
        oneA = a % 10;
        oneB = b % 10;
        a /= 10;
        b /= 10;

        if (oneA + oneB >= 10) {
            return 0;
        }
    }
    return realA + realB;
}

int main() {
    // input variable
    int n;
    cin >> n;

    vector<int> arr(n);
    int maxV = -1;

    for(int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        arr[i] = x;
    }

    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            int temp = iscarry(arr[i], arr[j]);

            if(temp > 0) {
            for(int k = j + 1; k < n; k++) {
                if(iscarry(temp, arr[k]) != 0) { 
                    temp += arr[k];
                    maxV = max(maxV, temp);
                    temp -= arr[k];
                }
            }
            }
        }
    }

    cout << maxV;

    
    return 0;
}