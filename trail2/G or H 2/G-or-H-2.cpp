#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Input variable
    int n;
    cin >> n;

    vector<char> coor(101);
    int maxV = 0;
    int maxRange = -1;
    int minRange = 99999;
    for(int i = 0; i < n; i++) {
        int x;
        char alpha;
        cin >> x >> alpha;
        maxRange = max(x, maxRange);
        minRange = min(x, minRange);

        coor[x] = alpha;
    }

    for(int i = minRange; i <= maxRange - 1; i++) {
        if(coor[i] == '\0')
            continue;

        for(int j = i; j <= maxRange; j++) {
            if(coor[i] == '\0')
                continue;
            int first = -1, end = -1;
            int Gcount = 0, Hcount = 0;

            for(int k = i; k <= j; k++) {
                if(first == -1 && coor[k] != '\0')
                    first = k;

                if(coor[k] == 'G') {
                    Gcount++;
                    end = k;
                }
                else if(coor[k] == 'H') {
                    Hcount++;
                    end = k;
                }
            }

            if((first != -1 && first != end) && (Gcount == Hcount || (Gcount > 0 && Hcount == 0) || (Gcount == 0 && Hcount > 0))) {
                maxV = max(maxV, end - first);
            }
        }
    }

    cout << maxV;
    return 0;
}