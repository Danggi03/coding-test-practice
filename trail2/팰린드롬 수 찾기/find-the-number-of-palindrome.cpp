#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool palindrome(int i) {
    int original = i;
    int reverse = 0;
    int count;
    vector<int> integer;

    while(i > 0) {
        integer.push_back(i % 10);
        i /= 10;
    }
    
    for(int i = 0; i < integer.size(); i++) {
        reverse += integer[i] * (pow(10, (integer.size() - i - 1)));
    }

    if(original == reverse)
        return true;
    else
        return false;

}

int main() {
    int x, y;
    cin >> x >> y;

    int count = 0;

    for(int i = x; i <= y; i++) {
        if(palindrome(i))
            count++;
    }

    cout << count;
    return 0;
}