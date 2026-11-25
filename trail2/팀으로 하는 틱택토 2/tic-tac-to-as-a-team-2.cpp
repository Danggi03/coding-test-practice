#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> convert(int n) {
    vector<int> result;

    while(n > 0) {
        result.push_back(n % 10);
        n /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}




int main() {
    // INPUT variable
    int n;
    int win = 0;
    vector<vector<int>> tictecto(3, vector<int>(3, 0));
    for(int i = 0; i < 3; i++) {
        cin >> n;
        tictecto[i] = convert(n);
    }

    for(int i = 1; i <= 9 - 1; i++) {
        for(int j = i + 1; j <= 9; j++) {
            int count_i = 0;
            int count_j = 0;
            bool is_check = true;
            bool is_next = false;
            // 가로
            for(int x = 0; x < 3; x++) {
                count_i = 0;
                count_j = 0;
                is_check = true;

                for(int y = 0; y < 3; y++) {
                    if(tictecto[x][y] != i && tictecto[x][y] != j) {
                        is_check = false;
                        break;
                    }
                    if(tictecto[x][y] == i)
                        count_i++;
                    else if(tictecto[x][y] == j)
                        count_j++;
                }
                if(is_check && !(count_i == 3 && count_j == 0) && !(count_i == 0 && count_j == 3)) {
                    win++;
                    is_next = true;
                    break;
                }
            }
            if(is_next)
                continue;

            // 세로
            for(int y = 0; y < 3; y++) {
                count_i = 0;
                count_j = 0;
                is_check = true;
                for(int x = 0; x < 3; x++) {
                    if(tictecto[x][y] != i && tictecto[x][y] != j) {
                        is_check = false;
                        break;
                    }
                    if(tictecto[x][y] == i)
                        count_i++;
                    else if(tictecto[x][y] == j)
                        count_j++;
                }
                if(is_check && !(count_i == 3 && count_j == 0) && !(count_i == 0 && count_j == 3)) {
                    win++;
                    is_next = true;
                    break;
                }
            }
            if(is_next)
                continue; 

            // 우대
            count_i = 0;
            count_j = 0;
            is_check = true;

            for(int x = 0; x < 3; x++) {
                if(tictecto[x][x] != i && tictecto[x][x] != j) {
                    is_check = false;
                    break;
                }
                if(tictecto[x][x] == i)
                    count_i++;
                else if(tictecto[x][x] == j)
                    count_j++;
            }
            if(is_check && !(count_i == 3 && count_j == 0) && !(count_i == 0 && count_j == 3)) {
                win++;
                continue;
            }

            // 좌대
            is_check = true;
            count_i = 0;
            count_j = 0;
            for(int x = 2, y = 0; x >= 0; x--, y++) {
                if(tictecto[x][y] != i && tictecto[x][y] != j) {
                    is_check = false;
                    break;
                }
                if(tictecto[x][y] == i)
                    count_i++;
                else if(tictecto[x][y] == j)
                    count_j++;
            }
            if(is_check && !(count_i == 3 && count_j == 0) && !(count_i == 0 && count_j == 3)) {
                win++;
                continue;
            }
        }
    }

    cout << win;
    return 0;
}