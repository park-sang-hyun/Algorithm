#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
using namespace std;

int tc, n, k, diff, cnt;
vector <int> vec;

int main() {
	fastio;

	cin >> tc;
	for (int t = 0; t < tc; t++) {
		diff = 987654321, cnt = 0;

		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			vec.push_back(num);
		}

		sort(vec.begin(), vec.end());

		int i=0, j = vec.size() - 1;
		while(i < j){
			int sum = vec[i] + vec[j];

			if (diff == abs(sum - k)) cnt++;
			else if (diff > abs(sum - k)) {
				diff = abs(sum - k);
				cnt = 1;
			}

			if (sum >= k) j--;
			if (sum <= k) i++;
		}

		cout << cnt << "\n";

		vec.clear();
	}

	return 0;
}
