#include <iostream>
#include <vector>
using namespace std;

bool v[2001];
int n, m, ans = 0;
vector<vector<int>> man(2000);

void go(int x, int cnt) {
	if (cnt == 5) {
		ans = 1;
		return;
	}

	for (int i = 0; i < man[x].size(); i++) {
		if (v[man[x][i]] == true) continue;

		v[man[x][i]] = true;
		go(man[x][i], cnt + 1);
		if (ans == 1) return;
		v[man[x][i]] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		man[a].push_back(b);
		man[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2000; j++) v[j] = false;
		v[i] = true;
		go(i, 1);
		if(ans == 1) break;
	}

	cout << ans;

	return 0;
}
