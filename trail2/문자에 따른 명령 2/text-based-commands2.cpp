#include <iostream>
#include <algorithm>
#include <string>

// north, east, south, west
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

using namespace std;

int main() {
    // input variable
    string command;
    cin >> command;
    
    int angle = 0;
    pair<int, int> coordinate = make_pair(0, 0);

    for(int i = 0; i < command.length(); i++) {
        if(command[i] == 'L') {
            angle = (angle - 1 + 4) % 4;
        }
        else if(command[i] == 'R') {
            angle = (angle + 1) % 4;
        }
        else {
            coordinate.first += dx[angle];
            coordinate.second += dy[angle];
        }
    }

    cout << coordinate.first << " " << coordinate.second;
    return 0;
}