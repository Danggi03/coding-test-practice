#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Input Variable
	int n;
	cin >> n;

	vector<int> arr(n);
	for(auto& var : arr) {
		cin >> var;
	}

	int find = 0;

	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			double temp = 0;
			int count = 0;
			//range calculate
			for(int x = i; x <= j; x++) {
				temp += arr[x];
				count++;
			}

			//average
			temp /= count;
			
			for(int x = i; x <= j; x++) {
				if(arr[x] == temp) {
					find++;
					break;
				}
			}
		}
	}

	cout << find;
    return 0;
}