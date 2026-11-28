#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
     
    vector<int> A(n);
    vector<int> B(n);
    int cost = 0;
    for(auto& var : A) {
        cin >> var;
    }
    for(auto& var : B) {
        cin >> var;
    }
    
    for(int i = 0; i < n - 1; i++) {
        int differ = A[i] - B[i];

        A[i + 1] += differ;
        cost += differ;
    }

    cout << cost;
    return 0;
}