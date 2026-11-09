#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // input variable
    string a;
    cin >> a;

    int count = 0;
    if(a.length() >= 4) {
        for(int i = 0; i < a.length() - 2; i++) {
            if(a[i] == '(' && a[i + 1] == '(') {
                for(int j = i + 2; j < a.length() - 1; j++) {
                    if(a[j] == ')' && a[j + 1] == ')') {
                        count++;
                    }
                } 
            }
        }
    }
    cout << count;
    return 0;
}