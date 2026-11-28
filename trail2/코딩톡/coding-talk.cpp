#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct p {
    int non_check;
    string prediction;
};

string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    int n, m, check_p;
    cin >> n >> m >> check_p;

    check_p--;

    string human = abc.substr(0, n);
    vector<p> p_arr(m);

    for(int freq = 0; freq < m; freq++) {
        char chat;
        int no_check;
        cin >> chat >> no_check;

        if(no_check == 0) {
            p_arr[freq].non_check = no_check;
            continue;
        }

        if(freq == 0 || no_check != p_arr[freq - 1].non_check) {
            p_arr[freq].non_check = no_check;
            p_arr[freq].prediction = human;
        }
        else {
            p_arr[freq].non_check = no_check;
            p_arr[freq].prediction = p_arr[freq - 1].prediction;
        }
        for(int i = 0; i <= freq; i++) {
            if(p_arr[i].non_check == 0) continue;
            auto remove_human = p_arr[i].prediction.find(chat);

            if(remove_human != string::npos) {
                p_arr[i].prediction.erase(remove_human, 1);
            }
        }
    }

    for(int i = 0; i < p_arr[check_p].prediction.size(); i++) {
        cout << p_arr[check_p].prediction[i] << " ";
    }


    return 0;
}