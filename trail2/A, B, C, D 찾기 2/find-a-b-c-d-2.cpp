#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec(15);

    for(auto& var : vec) {
        cin >> var;
    }

    sort(vec.begin(), vec.end());

    int A = vec[0];
    int B = vec[1];
    int C, D;
    
    for(int temp_c = 2; temp_c < 15; temp_c++) {
        C = vec[temp_c];
        for(int temp_d = temp_c + 1; temp_d < 15 - 1; temp_d++) {
            D = vec[temp_d];

            vector<int> made = {A, B, C, D, A+B, B+C, C+D, D+A, A+C, B+D, A+B+C, A+B+D, A+C+D, B+C+D, A+B+C+D};
            sort(made.begin(), made.end());

            if(made == vec) {
                cout << A << " " << B << " " << C << " " << D;
                return 0;
            }
        }
    }

    // for(auto& var : vec) {
    //     cout << var << " ";
    // }
    return 0;
}