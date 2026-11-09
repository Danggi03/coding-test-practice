#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // input variable
    int n, k, p, t;
    cin >> n >> k >> p >> t;

    vector<pair<int, int>> timeTable(251);
    vector<pair<bool, int>> humanStat(101, {false, 0});
    
    // infection record
    for(int freq = 0; freq < t; freq++) {
        int time, x, y;
        cin >> time >> x >> y;
        timeTable[time] = {x, y};
    }

    // infection init
    humanStat[p] = {true, k};

    for(int i = 0; i < timeTable.size(); i++) {
        // skip
        if(timeTable[i] == make_pair(0, 0)) {
            continue;
        }

        // a = infection, b = human
        if(humanStat[timeTable[i].first].first == true && humanStat[timeTable[i].second].first == false) {
            if(humanStat[timeTable[i].first].second >= 1) {
                humanStat[timeTable[i].second].first = true;
                humanStat[timeTable[i].second].second = k;
                humanStat[timeTable[i].first].second--;
            }
        }
        // a = human, b = infection
        else if(humanStat[timeTable[i].first].first == false && humanStat[timeTable[i].second].first == true) {
            if(humanStat[timeTable[i].second].second >= 1) {
                humanStat[timeTable[i].first].first = true;
                humanStat[timeTable[i].first].second = k;
                humanStat[timeTable[i].second].second--;
            }
        }
        // a = infection, b = infection
        else if(humanStat[timeTable[i].first].first == true && humanStat[timeTable[i].second].first == true) {
            humanStat[timeTable[i].second].second--;
            humanStat[timeTable[i].first].second--;
        }
    }


    for(int i = 1; i <= n; i++) {
        cout << humanStat[i].first;
    }
    return 0;
}