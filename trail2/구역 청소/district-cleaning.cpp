#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;


    if(a <= c && d <= b) {
        cout << b - a;
        return 0;
    }
    else if(c <= a && b <= d) {
        cout << d - c;
        return 0;
    }
    else if(a <= c && c <= b) {
        cout << (b - a) + (d - b);
        return 0;
    }
    else if(c <= a && a <= d) {
        cout << (d - c) + (b - d); 
        return 0;
    }

    cout << (b - a) + (d - c);
    return 0;
}