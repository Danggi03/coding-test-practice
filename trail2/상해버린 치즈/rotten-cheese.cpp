#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, d, s;
    cin >> n >> m >> d >> s;

    vector<vector<int>> info(n + 1, vector<int>(m + 1, 1000));
    vector<pair<int, int>> sick_info;
    // vector<vector<int>> cheese(m + 1);
    vector<unordered_set<int>> cheese(m + 1);

    unordered_set<int> candidate;
    int maxSickV = 0;

    for(int i = 0; i < d; i++) {
        int human, eat, time;
        cin >> human >> eat >> time;
        
        cheese[eat].insert(human); // cheese array
        
        info[human][eat] = min(info[human][eat], time);
    }

    for(int i = 0; i < s; i++) {
        int human, tsick;
        cin >> human >> tsick;
        sick_info.push_back(make_pair(human, tsick));
    }

// 3. 1번 치즈부터 m번 치즈까지 상했을 가능성 검증
    for (int c = 1; c <= m; c++) {
        bool is_possible = true;

        // 아픈 사람 전원이 c번 치즈를 아프기 전에 먹었는지 확인
        for (int i = 0; i < s; i++) {
            int sick_human = sick_info[i].first;
            int tsick = sick_info[i].second;

            // 한 명이라도 안 먹었거나(1000) 아픈 이후(>= tsick)에 먹었다면 탈락
            if (info[sick_human][c] >= tsick) {
                is_possible = false;
                break;
            }
        }

        // 아픈 사람 모두가 아프기 전에 먹은 치즈라면, 전체 섭취 인원수로 최댓값 갱신
        if (is_possible) {
            maxSickV = max(maxSickV, (int)cheese[c].size());
        }
    }
// 아픈 사람 모두가 아프기 전에 먹은 치즈라면, 전체 섭취 인원수로 최댓값 갱신


    cout << maxSickV;

    return 0;
}