#include <iostream>
#include <string>
using namespace std;

int main() {
    string parenthesis;
    cin >> parenthesis;

    int count = 0;
    for(int i = 0; i < parenthesis.size(); i++) {
        if (parenthesis[i] == '(') {
            for(int x = i; x < parenthesis.size(); x++) {
                if(parenthesis[x] == ')')
                    count++;
            }
        } 
    }

    cout << count;
    return 0;
}