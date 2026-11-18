#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> developer(5);

    int tempCexam = 0;
    int resultminus = 999999999;
    for(auto& var : developer) {
        cin >> var;
        tempCexam += var;
    }

    for(int i = 0; i < developer.size() - 1; i++) {
        for(int j = i + 1; j < developer.size(); j++) {
            int tempA = developer[i] + developer[j];

            for(int k = 0; k < developer.size() - 1; k++) {
                if(k == i || k == j) continue;
                for(int l = k + 1; l < developer.size(); l++) {
                    if(l == i || l == j) continue;
                    int tempB = developer[k] + developer[l];
                    int tempC = tempCexam - (tempA + tempB);
                    if(tempA == tempB || tempA == tempC || tempB == tempC) continue;
                    int tmpMAX = -1;
                    int tmpMIN = 999999999;
                    
                    tmpMAX = max(tmpMAX, tempA);
                    tmpMAX = max(tmpMAX, tempB);
                    tmpMAX = max(tmpMAX, tempC);
                    tmpMIN = min(tmpMIN, tempA);
                    tmpMIN = min(tmpMIN, tempB);
                    tmpMIN = min(tmpMIN, tempC);

                    resultminus = min(resultminus, tmpMAX - tmpMIN);
                }
            }
        }
    }
    if(resultminus == 999999999)
        cout << -1;
    else
        cout << resultminus;
    return 0;
}