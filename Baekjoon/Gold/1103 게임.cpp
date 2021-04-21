#include <iostream>
#include <math.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int map[51][51], dp[51][51];
bool v[51][51];
int n, m;
int dy[] = { -1, 0, 1, 0 }, dx[] = { 0,1,0,-1 };

int go(int y, int x) {
	if (v[y][x] == 1) {
		cout << -1;
		exit(0);
	}

	if (dp[y][x] != 0) return dp[y][x];

	v[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i] * map[y][x];
		int tx = x + dx[i] * map[y][x];

		if (ty < 0 || tx < 0 || ty >= n || tx >= m || map[ty][tx] == -1) continue;
		dp[y][x] = max(dp[y][x], go(ty, tx) + 1);
	}

	v[y][x] = 0;

	return dp[y][x];
}

int main() {
	fastio;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char tmp;

			cin >> tmp;
			if (tmp != 'H') map[i][j] = tmp - 48;
			else map[i][j] = -1;
		}

	cout << go(0, 0) + 1;

	return 0;
}
