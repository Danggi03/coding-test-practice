#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    // input variable
    int n, m, k;
    cin >> n >> m >> k;
    
    // result variable
    vector<int> student(n + 1);
    vector<int> fines;
    
    for(int freq = 0; freq < m; freq++) {
        int x;
        cin >> x;
        student[x]++;
        if(student[x] >= k) {
            fines.push_back(x);
        }
    }
    if(fines.size() > 0)
        cout << fines[0];
    else
        cout << -1;

    return 0;
}