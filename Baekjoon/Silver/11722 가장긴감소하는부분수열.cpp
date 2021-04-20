#include <iostream>
#include <vector>
using namespace std;

int a[1001], d[1001], MAX = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		d[i] = 1;

		for (int j = 0; j < i; j++) {
			if (a[i] < a[j] && d[i] < d[j] + 1) d[i] = d[j] + 1;
		}

		if (MAX < d[i]) MAX = d[i];
	}

	cout << MAX;

	return 0;
}
