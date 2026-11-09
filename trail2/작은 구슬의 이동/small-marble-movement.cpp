#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// E, W, S, N xor bit way.
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool ismatch(const int& x, const int& y, const int& size) {
    return x > 0 && x <= size && y > 0 && y <= size;
}

int direct(const char& word) {
    if(word == 'U') {
        return 3;
    }
    else if(word == 'D') {
        return 2;
    }
    else if(word == 'R') {
        return 0;
    }
    else if(word == 'L') {
        return 1;
    }
}

int main() {
    // input variable
    int n, t, r, c;
    char word;
    cin >> n >> t;

    // vector<vector<int>> arr(n, vector<int>(n, 0));
    cin >> r >> c >> word;
    pair<int, int> coordinate = make_pair(r, c);
    int angle = direct(word);

    while(t--) {
        int nx = coordinate.first + dx[angle], 
            ny = coordinate.second + dy[angle];
        if(!ismatch(nx, ny, n)) {
            angle ^= 1;
            continue;
        }
        coordinate.first = nx;
        coordinate.second = ny;
    }

    cout << coordinate.first << " " << coordinate.second;

    
    return 0;
}