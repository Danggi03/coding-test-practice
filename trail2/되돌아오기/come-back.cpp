#include <iostream>
#include <algorithm>
using namespace std;

//N, E, S, W 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int directConvert(const char& direct) {
    if(direct == 'N') {
        return 0;
    }
    else if(direct == 'E') {
        return 1;
    }
    else if(direct == 'S') {
        return 2;
    }
    else if(direct == 'W') {
        return 3;
    }
}

int running(pair<int, int>& coor, const int& n) {
    int time = 0;
    for(int freq = 0; freq < n; freq++) {
        char direct;
        int t;
        cin >> direct >> t;

        int angle = directConvert(direct);

        while(t--) {
            time++;
            coor.first += dx[angle];
            coor.second += dy[angle];
            if(coor.first == 0 && coor.second == 0) {
                return time;
            }
        }
    }
    return -1;
}


int main() {
    // input variable
    int n;
    cin >> n;
    
    // init
    pair<int, int> coor = make_pair(0,0);
    int count = running(coor, n);

    cout << count;
    return 0;
}