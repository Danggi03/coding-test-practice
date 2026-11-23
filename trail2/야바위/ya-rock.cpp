#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cup {
    int x;
    int y;
    int open;
};

int main() {
    // input variable
    int n;
    cin >> n;

    vector<cup> cups(n);
    int score = 0;

    for(auto& var : cups) {
        cin >> var.x >> var.y >> var.open;
    }

    for(int i = 1; i <= 3; i++) {
        vector<int> cuplist(4);
        int temp = 0;
        cuplist[i] = 1;
    
        for(int freq = 0; freq < n; freq++) {
            swap(cuplist[cups[freq].x], cuplist[cups[freq].y]);
            if(cuplist[cups[freq].open] == 1)
                temp++;
        }
        score = max(score, temp);
    }

    cout << score;
    return 0;
}