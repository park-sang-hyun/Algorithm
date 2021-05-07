#include <iostream>
#include <vector>
#include <string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m, par[1000001];

int find(int x) {
	if (par[x] == x) return x;

	return par[x] = find(par[x]);
}

void uni(int y, int x) {
	y = find(y);
	x = find(x);

	if (x < y) par[y] = x;
	else par[x] = y;
}

int main() {
	fastio;

	cin >> n >> m;

	for (int i = 0; i <= n; i++) par[i] = i;

	for (int i = 0; i < m; i++) {
		int ord, a, b;
		cin >> ord >> a >> b;

		if (ord == 0) uni(a, b);
		else {
			a = find(a);
			b = find(b);

			if (a == b) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
	
	return 0;
}
