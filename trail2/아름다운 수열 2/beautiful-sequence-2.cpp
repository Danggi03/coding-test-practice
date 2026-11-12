#include <iostream>
#include <vector>
#include <algorithm>
//map 을 사용하여 풀어보기
#include <unordered_map>
using namespace std;

int main() {
    // Input variable
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(auto& var: arr) {
        cin >> var;
    }
    vector<int> arrB(m);
    for(auto& var: arrB) {
        cin >> var;
    }
    
    unordered_map<int, int> numB;
    int find = 0;
    for(auto& var: arrB) {
        numB[var]++;
    }

    for(int i = 0; i <= n - m; i++) {
        unordered_map<int, int> numK;
        for(int j = i; j < i + m; j++) {
            numK[arr[j]]++;
        }
        if(numB == numK)
            find++;
    }

    cout << find;


    return 0;
}