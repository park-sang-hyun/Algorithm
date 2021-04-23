#include <iostream>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
using namespace std;

ll x, y, z;
int answer = -1;

int BinarySearch(ll start, ll end, int target) {
	while (start <= end) {
		ll mid = start + (end - start) / 2;
		int percent = (y + mid) * 100 / (x + mid) ;

		if (percent < target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
			answer = mid;
		}
	}

	return answer;
}

int main() {
	fastio;
   
	cin >> x >> y;

	z = y * 100 / x;

	BinarySearch(1, x, z + 1);

	cout << answer;

	return 0;
}
