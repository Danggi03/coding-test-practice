#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct product {
    int p;
    int s;
};

bool cmp(const product& a, const product& b) {
    if(a.p + a.s != b.p + b.s)
        return a.p + a.s < b.p + b.s;
    else
        return a.p < b.p;
};

int main() {
    // Input variable
    int n , b;
    cin >> n >> b;

    vector<product> gift(n);
    int maxS = 0;

    for(auto& var : gift) {
        cin >> var.p >> var.s;
    }

    sort(gift.begin(), gift.end(), cmp);

    for(int coupon = 0; coupon < n; coupon++) {
        int temp = 0;
        int bill = b - ((gift[coupon].p / 2) + gift[coupon].s);
        if(bill >= 0)
            temp = 1;
        else
            continue;
        for(int i = 0; i < n; i++) {
            if(coupon == i) continue;

            bill -= (gift[i].p + gift[i].s);

            if(bill >= 0) {
                temp++;
            }
            else
                break;
        }
        maxS = max(maxS, temp); 
    }

    cout << maxS;
    return 0;
}