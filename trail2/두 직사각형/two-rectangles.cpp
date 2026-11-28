#include <iostream>
using namespace std;

int main() {
    // INPUT variable

    int x1, y1, x2, y2;
    int a1, b1, a2, b2;
    
    cin >> x1 >> y1 >> x2>> y2 >> a1 >> b1 >> a2 >> b2;

    if(x2 < a1) {
        cout << "nonoverlapping";
        return 0;
    }
    else if(y2 < b1) {
        cout << "nonoverlapping";
        return 0;
    }
    else if(a2 < x1) {
        cout << "nonoverlapping";
        return 0;
    }
    else if(b2 < y1) {
        cout << "nonoverlapping";
        return 0;
    }

    cout << "overlapping";
    return 0;
}