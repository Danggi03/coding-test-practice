#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coor(101);

    for(int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;

        for(int a = x1; a <= x2; a++) {
            coor[a]++;
        }
    }

    for(auto& var: coor) {
        if(var == n) {
            cout << "Yes";
            return 0;
        }   
    }
    cout << "No";
    return 0;
}