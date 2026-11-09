#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    int coordinate = 1000;
    char direct;
    int count = 0;

    vector<int> areas(2001);
    //test case
    cin >> n;

    for(int freq = 0; freq < n; freq++) {
        cin >> x >> direct;

        if(direct == 'R') {
            for(int i = 0; i < x; i++) {
                areas[coordinate]++;
                coordinate++;
            }
        }
        else {
            for(int i = 0; i < x; i++) {
                coordinate--;
                areas[coordinate]++;
            }
        }
    }

    for(int i = 0; i < areas.size() - 1; i++) {
        if(areas[i] >= 2) {
            count++;
        }
    }

    cout << count;

    return 0;
}