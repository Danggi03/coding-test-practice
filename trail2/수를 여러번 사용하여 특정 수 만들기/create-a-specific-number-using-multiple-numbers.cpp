#include <iostream>

using namespace std;

int main() {
    // INPUT DATA
    int a, b, c;
    cin >> a >> b >> c;

    int maxV = 0;

    int tempA = 0;
    int tempB = 0;

    for(int i = 0; tempA <= c; i++) {
        tempA = a * i;
        for(int j = 0; tempB <= c; j++) {
            tempB = b * j;

            if(tempA + tempB <= c){
                maxV = max(maxV, tempA + tempB);
            }
        }
        tempB = 0;
    }
    
    cout << maxV;
    return 0;
}