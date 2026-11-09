#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void findZero(string& binary) {
    for(int i = 1; i < binary.length(); i++) {
        if(binary[i] == '0') {
            binary[i] = '1';
            return;
        }
    }
    binary[binary.length() - 1] = '0';
    
    return;
}

int main() {
    // input variable
    string binary;
    cin >> binary;


    int number = 0;

    findZero(binary);

    //(n)2 -> (n)10
    int index = binary.length() - 1;
    for(int i = 0; i < binary.length(); i++) {
        number += (1 << index) * (int) (binary[i] - '0');
        index--;
    }

    cout << number;
    return 0;
}