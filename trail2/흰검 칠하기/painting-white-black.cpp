#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct info{
    int w_count = 0;
    int b_count = 0;
};

int main() {
    int n, x;
    int coordinate = 1e5;
    char direct;

    vector<pair<char, info>> tiles(2e5+1);
    int color[3] = {0, 0, 0}; // white, black, gray
    //test case
    cin >> n;
    
    for(int freq = 0; freq < n; freq++) {
        cin >> x >> direct;
        
        if(direct == 'R') { //black, positive
            for(int i = 0; i < x; i++, coordinate++) {
                if (tiles[coordinate].first != 'G') {
                    tiles[coordinate].first = 'B';
                    tiles[coordinate].second.b_count++;
                    if(tiles[coordinate].second.w_count >= 2 && tiles[coordinate].second.b_count >= 2) {
                        tiles[coordinate].first = 'G';
                    }
                }
            }
            coordinate--; // recover point
        }
        else { //white , negative
            for(int i = 0; i < x; i++, coordinate--) {
                if(tiles[coordinate].first != 'G') {
                    tiles[coordinate].first = 'W';
                    tiles[coordinate].second.w_count++;
                    if(tiles[coordinate].second.w_count >= 2 && tiles[coordinate].second.b_count >= 2) {
                        tiles[coordinate].first = 'G';
                    }
                }
            }
            coordinate++; // recover point
        }
    }

    for(auto& [first, second] : tiles) {
        if(first == 'W')
            color[0]++;
        else if(first == 'B')
            color[1]++;
        else if(first == 'G')
            color[2]++;
    }

    for(int freq : color) {
        cout << freq << " ";
    }

    return 0;
}