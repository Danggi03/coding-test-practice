#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_INT 100000000
int maxIndex;

using namespace std;
int compareVector(const vector<int>& a, const vector<int>& b) {
    int time;
    for(int time = 1; time <= a.size(); time++) {
        if(a[time] == b[time])
            return time;
        else if(a[time] == MAX_INT)
            return -1;
    }
}

void continueTime(vector<int>& arr, int& count) {
    char direct;
    int Atime = 0;

    for(int i = 0; i < count; i++) {
        int time;
        cin >> direct >> time;
        while(time--) {
            Atime++;
            if(direct == 'R') {
                arr[Atime] = arr[Atime - 1] + 1;
            }
            else {
                arr[Atime] = arr[Atime - 1] - 1;
            }
        }
    }
    maxIndex = ++Atime;
}
int main() {
    //input variable
    int n, m;
    cin >> n >> m;

    //result variable
    vector<int> arrA(1e6);
    vector<int> arrB(1e6);
    int result = 0;
    //core
    continueTime(arrA, n);
    continueTime(arrB, m);
    arrA[maxIndex] = MAX_INT;

    result = compareVector(arrA, arrB);

    cout << result;

    

    
    return 0;
}