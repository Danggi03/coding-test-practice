#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n;
    str.reserve(n);
    cin >> str;

    int maxL = 0;

    for(int i = 0; i < n; i++) {
        if(str[i] == '1') continue;

        str[i] = '1';
        int prev = -1;
        int temp = 999999;

        for(int freq = 0; freq < n; freq++) {
            if(str[freq] == '1') {
                if(prev != -1) {
                    temp = min(temp, freq - prev);
                }
                prev = freq;
            }
        }
        maxL = max(temp, maxL);

        str[i] = '0';
    }

    cout << maxL;
    return 0;
}