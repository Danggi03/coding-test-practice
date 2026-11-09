#include <iostream>
#include <algorithm>

using namespace std;

//east north west south 동 북 서 남
int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};

int main() {
    // input variable
    int n;
    cin >> n;

    pair<int, int> coordinate = make_pair(0, 0);

    for(int i = 0; i < n; i++) {
        char direct;
        int count;
        cin >> direct >> count;

        // east
        if(direct == 'E') {
            while(count--) {
                coordinate.first += dx[0];
            }
        }
        else if(direct == 'N') {
            while(count--) {
                coordinate.second += dy[1];
            }
        }
        else if(direct == 'W') {
            while(count--) {
                coordinate.first += dx[2];
            }
        }
        else if(direct == 'S') {
            while(count--) {
                coordinate.second += dy[3];
            }
        }
    }

    cout << coordinate.first << " " << coordinate.second;
    return 0;
}