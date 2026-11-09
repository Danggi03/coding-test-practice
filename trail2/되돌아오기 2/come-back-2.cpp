#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//N E S W mathtic
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; 

int running(pair<int, int>& coor) {
    // input variable
    string cmd;
    cin >> cmd;

    int angle = 0;

    for(int i = 0; i < cmd.length(); i++) {
        if(cmd[i] == 'F') {
            coor.first += dx[angle];
            coor.second += dy[angle];
            if(coor.first == 0 && coor.second == 0) {
                return i + 1;
            }
        }
        else if(cmd[i] == 'L') {
            angle = (angle - 1 + 4) % 4;
        }
        else if(cmd[i] == 'R') {
            angle = (angle + 1) % 4;
        }
    }
    return -1;
}
int main() {
    pair<int, int> coor = make_pair(0, 0);

    cout << running(coor);
    return 0;
}