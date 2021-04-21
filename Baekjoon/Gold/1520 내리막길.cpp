#include <iostream>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int map[501][501], dp[501][501];
bool v[501][501];
int n, m;
int dy[] = { -1, 0, 1, 0 }, dx[] = { 0,1,0,-1 };

int go(int y, int x) {
	if (y == n - 1 && x == m - 1) return 1;

	if (v[y][x] == false) {
		v[y][x] = true;

		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			if (ty < 0 || tx < 0 || ty >= n || tx >= m) continue;
			if (map[ty][tx] < map[y][x]) dp[y][x] += go(ty, tx);	
		}
	}
	
	return dp[y][x];
}

int main() {
	fastio;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> map[i][j];
		
	cout << go(0, 0);

	return 0;
}
