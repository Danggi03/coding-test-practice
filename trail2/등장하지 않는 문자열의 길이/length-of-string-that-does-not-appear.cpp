#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string str;
    str.reserve(n);
    cin >> n >> str;

    int maxL = 0;

    for(int i = 0; i < n; i++) {
        int j = 1;
        for(; j <= n - i; j++) {
            bool is_check = true;
            
            string temp = str.substr(i, j);
//여기부분이 이상
            for(int k = i + 1; k <= n - j; k++) {
                string str_temp = str.substr(k, j);
                if(temp == str_temp) {
                    is_check = false;
                    break;
                }
            }
            if(is_check) {
                maxL = max(maxL, j);
                break;
            }
        }
    }

    cout << maxL;
    return 0;
}