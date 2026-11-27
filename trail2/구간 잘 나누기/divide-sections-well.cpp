#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> seq(n);

    int minV = 0;
    int maxV = 0;
    for(auto& var: seq) {
        cin >> var;
        minV = max(minV, var);
        maxV += var;
    }

    for(int min_num = minV; min_num <= maxV; min_num++) {
        int temp_sum = 0;
        int i = 0;
        int section = m;
    
        while(true) {
            if(section < 1)
                break;
            else if(i == n && temp_sum <= min_num) {
                cout << min_num;
                return 0;
            }

            temp_sum += seq[i];
            // cout << temp_sum << " || " << seq[i] << endl;
            // 칸 나누기
            if(temp_sum > min_num) {
                section--;
                temp_sum = seq[i];
            }

            i++;
        }
    }
    return 0;
}