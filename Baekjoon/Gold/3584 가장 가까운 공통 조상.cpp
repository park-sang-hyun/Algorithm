#include <iostream>
#include <vector>
#include <string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int tc, n, par[10001], a, b;

vector <int> v1, v2;

void find1(int x) {
	if (x == par[x]) return;

	v1.push_back(par[x]);
	find1(par[x]);
	return;
}

void find2(int x) {
	if (x == par[x]) return;

	v2.push_back(par[x]);
	find2(par[x]);
	return;
}

int main() {
	fastio;

	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> n;

		for (int i = 0; i <= n; i++) par[i] = i;

		for (int i = 1; i < n; i++) {
			cin >> a >> b;

			par[b] = a;
		}

		cin >> a >> b;

		v1.push_back(a);
		find1(a);

		v2.push_back(b);
		find2(b);

		int ans = -1;

		for (int i = 0; i < v1.size(); i++) {
			for (int j = 0; j < v2.size(); j++) {
				if (v1[i] == v2[j]) {
					ans = v1[i];
					break;
				}
			}
			if (ans != -1) break;
		}

		cout << ans << "\n";
		v1.clear();
		v2.clear();
	}

	return 0;
}
