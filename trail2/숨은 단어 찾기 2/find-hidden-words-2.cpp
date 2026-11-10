#include <iostream>
#include <string>
#include <vector>

using namespace std;

int rangeSearch(const vector<string>& str, const int& x, const int& y, const int& n, const int& m) {
    int find = 0;
    // range search
    if(x > 1) {
        int count = 0;
        for(int i = 1; i < 3; i++) {
            if(str[x - i][y] != 'E')
                break;
            count++;
        }
        if(count == 2)
            find++;
    }

    // 2.
    if(x > 1 && y < m - 2) {
        int count = 0;
        for(int i = 1; i < 3; i++) {
            if(str[x - i][y + i] != 'E')
                break;
            count++;
        }
        if(count == 2)
            find++;
    }

    // 3.
    if(y < m - 2) {
        int count = 0;
        for(int i = 1; i < 3; i++) {
            if(str[x][y + i] != 'E')
                break;
            count++;
        }
        if(count == 2)
            find++;
    }

    // 4.
    if(x < n - 2 && y < m - 2) {
        int count = 0;
        for(int i = 1; i < 3; i++) {
            if(str[x + i][y + i] != 'E')
                break;
            count++;
        }
        if(count == 2)
            find++;
    }

    // 5.
    if(x < n - 2) {
        int count = 0;
        for(int i = 1; i < 3; i++) {
            if(str[x + i][y] != 'E')
                break;
            count++;
        }
        if(count == 2)
            find++;
    }

    // 6.
    if(x < n - 2 && y > 1) {
        int count = 0;
        for(int i = 1; i < 3; i++) {
            if(str[x + i][y - i] != 'E')
                break;
            count++;
        }
        if(count == 2)
            find++;
    }

    // 7.
    if(y > 1) {
        int count = 0;
        for(int i = 1; i < 3; i++) {
            if(str[x][y - i] != 'E')
                break;
            count++;
        }
        if(count == 2)
            find++;
    }

    // 8.
    if(x > 1 && y > 1) {
        int count = 0;
        for(int i = 1; i < 3; i++) {
            if(str[x - i][y - i] != 'E')
                break;
            count++;
        }
        if(count == 2)
            find++;
    }

    return find;
}

int main() {
    // Input variable
    int n, m;
    cin >> n >> m;

    vector<string> str(n);
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            if(str[x][y] == 'L') {
                count += rangeSearch(str, x, y, n, m);
            }
        }
    }

    cout << count;
    return 0;
}