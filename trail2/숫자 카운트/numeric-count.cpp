#include <iostream>
#include <vector>
using namespace std;

struct info {
    int n;
    int strike;
    int ball;
};

int main() {
    // Input Variable
    int n;
    cin >> n;

    int find = 0;
    vector<info> arr(n);

    for(int freq = 0; freq < n; freq ++) {
        cin >> arr[freq].n >> arr[freq].strike >> arr[freq].ball;
    }




    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            for(int k = 1; k <= 9; k++) {
                if (i == j || j == k || i == k) 
                    continue;
                bool possible = true;
                for(int freq = 0; freq < n; freq++) {
                  int stemp = 0, btemp = 0;
                    int x, y, z;
                    x = arr[freq].n / 100;
                    y = (arr[freq].n / 10) % 10;
                    z = arr[freq].n % 10;

                    if(x == i)
                        stemp++;
                    if(y == j)
                        stemp++;
                    if(z == k)
                        stemp++;

                    if(x == j || x == k)
                        btemp++;
                    if(y == i || y == k)
                        btemp++;
                    if(z == i || z == j)
                        btemp++;
                    if((stemp != arr[freq].strike) || (btemp != arr[freq].ball)) {
                        possible = false;
                        break;
                        }
                }
                if(possible) {
                    find++;
                }
            }
        }
    }

    cout << find;
    return 0;
}