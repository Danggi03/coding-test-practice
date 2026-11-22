#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool interesting(int i) {
    unordered_map<int,int> count;
    int temp = 0;
    int interest = 0;

    while(i > 0) {
        temp++;
        count[i % 10]++;
        i /= 10;
    }

    for(int i = 0; i < count.size(); i++) {
        if(count[i] == temp - 1)
            return true;
    }
    return false;
}
int main() {
    int x, y;
    cin >> x >> y;

    int interesting_number = 0;

    for(int i = x; i <= y; i++) {
        if(interesting(i))
            interesting_number++;    
    }

    cout << interesting_number;
    return 0;
}