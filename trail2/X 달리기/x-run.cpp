#include <iostream>
#include <vector>

using namespace std;


int main() {
    int x;
    cin >> x;

    vector<int> sum(10001);
    sum[1] = 1;
    for(int i = 2; i < 10001; i++) {
        sum[i] += sum[i - 1] + i;
    }

    int time = 0;
    int speed = 1;
    int temp_x = 0;
    while(true) {
        if(temp_x == x)
            break;

        temp_x += speed;

        if(sum[speed + 1] + temp_x <= x) {
            speed++;
        }
        else if(sum[speed] + temp_x <= x) {
            speed = speed;
        }
        else
            speed--;

        time++;

    }

    cout << time;
    return 0;
}