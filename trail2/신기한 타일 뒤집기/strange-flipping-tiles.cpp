#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    char direct;
    int coordinate = 1e5;

    vector<char> tiles(2e5 + 1);
    vector<int> count(2, 0);
    //test case
    cin >> n;
    for(int freq = 0; freq < n; freq++) {
        cin >> x >> direct;

        if(direct == 'R') { // black, positive
            for(int i = 0; i < x; i++) {
                tiles[coordinate] = 'B';
                if(i < x - 1) // prevent overlap
                    coordinate++;
            }
        }
        else { // white, negative
            for(int i = 0; i < x; i++) {
                tiles[coordinate] = 'W';
                if(i < x - 1) // prevent overlap
                    coordinate--;
            } 
        }
    }

    
    for(char tile : tiles) {
        if(tile == 'W')
            count[0]++;
        else if(tile == 'B')
            count[1]++;
    }

    cout << count[0] << " " << count[1];

    return 0;
}