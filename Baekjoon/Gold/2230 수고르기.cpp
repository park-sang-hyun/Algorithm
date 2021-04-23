#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
using namespace std;

int  n, m;
ll diff = 2000000000;
vector <int> vec;

int main() {
	fastio;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	int i = vec.size() - 1, j = vec.size() - 1;
	while (i >= j && i >= 0 && j >= 0) {
		ll sum = vec[i] - vec[j];

		if (sum < m) j--;
		else if (sum > m) {
			i--;
			diff = min((ll)diff, sum);
		}
		else if (sum == m) {
			diff = m;
			break;
		}
	}

	cout << diff;

	return 0;
}
