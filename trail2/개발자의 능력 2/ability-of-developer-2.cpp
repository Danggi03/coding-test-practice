#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> developer(6);
    int tempCexam = 0;
    int resultminus = 999999999;
    
    for(auto& var: developer) {
        cin >> var;
        tempCexam += var;
    }
    for(int i = 0; i < developer.size() - 1; i++) {
        for(int j = i + 1; j < developer.size(); j++) {
            int tempA = developer[i] + developer[j];

            for(int k = 0; k < developer.size() - 1; k++) {
                if(k == i || k == j)
                    continue;
                for(int l = k + 1; l < developer.size(); l++) {
                    if(l == i || l == j)
                        continue;
                    int tempMAX = -1;
                    int tempMIN = 999999999;
                    int tempB = developer[k] + developer[l];      
                    int tempC = tempCexam - (tempA + tempB);
                    tempMAX = max(tempMAX, tempA);
                    tempMAX = max(tempMAX, tempB);
                    tempMAX = max(tempMAX, tempC);
                    tempMIN = min(tempMIN, tempA);
                    tempMIN = min(tempMIN, tempB);
                    tempMIN = min(tempMIN, tempC);
                    resultminus = min(resultminus, tempMAX - tempMIN);
                }
            }
        }
    }

    cout << resultminus;
    return 0;
}