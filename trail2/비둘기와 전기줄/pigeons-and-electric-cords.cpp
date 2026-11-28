#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pigeon(11, 999);
    int cross = 0;

    for(int i = 0; i < n; i++) {
        int p, pos;
        cin >> p >> pos;

        if(pigeon[p] != 1 && pigeon[p] != 0) {
            pigeon[p] = pos;
            continue;
        }

        if(pos == 1) {
            if(pigeon[p] == 0){
                cross++;
            }
        }
        else if(pos == 0) {
            if(pigeon[p] == 1)
                cross++;
        }
        
        pigeon[p] = pos;
    }

    cout << cross;
    return 0;
}