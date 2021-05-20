#include <iostream>
#include <algorithm>
using namespace std;

struct shark {
	int y, x, len, dir, siz, die = 0;
}sh[10001];

int n, m, scnt, ans, map[102][102], tmap[102][102];
int dx[] = { 0, 0, 0, 1, -1 }, dy[] = { 0, -1, 1, 0, 0 };

void fishing(int x) {
	for (int i = 1; i <= n; i++) {
		if (map[i][x] != 0) {
			sh[map[i][x]].die = 1;
			ans += sh[map[i][x]].siz;
			map[i][x] = 0;
			break;
		}	
	}
}

void move() {
	for (int i = 1; i <= scnt; i++) {
		if (sh[i].die == 1) continue;

		int y = sh[i].y;
		int x = sh[i].x;
		int dir = sh[i].dir;
		int len = sh[i].len;
		int ty, tx;

		while (1) {
			tx = x + len * dx[dir]; 
			ty = y + len * dy[dir];

			if (tx <= m && ty <= n && ty >= 1 && tx >= 1) break;
			if (dir == 1 && ty < 1) { 
				len -= y; 
				y = 2; 
				dir = 2; 
			}
			else if (dir == 2 && ty >= n + 1) { 
				len -= n - y;
				y = n;
				dir = 1; 
			}
			else if (dir == 3 && tx >= m + 1) { 
				len -= m - x; 
				x = m; 
				dir = 4;
			}
			else if (dir == 4 && tx < 1) {
				len -= x; 
				x = 2; 
				dir = 3; 
			}
		}

		if (tmap[ty][tx] != 0) {
			if (sh[tmap[ty][tx]].siz < sh[i].siz) {
				sh[tmap[ty][tx]].die = 1;
				tmap[ty][tx] = i;	
			}
			else sh[i].die = 1;
		}
		else tmap[ty][tx] = i;

		sh[i].y = ty;
		sh[i].x = tx;
		sh[i].dir = dir;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			map[i][j] = tmap[i][j];
			tmap[i][j] = 0;
		}
}

int main() {
	scanf("%d %d %d", &n, &m, &scnt);

	for (int i = 1; i <= scnt; i++) {
		scanf("%d %d %d %d %d", &sh[i].y, &sh[i].x, &sh[i].len, &sh[i].dir, &sh[i].siz);
		map[sh[i].y][sh[i].x] = i;
	}

	for (int i = 1; i <= m; i++) {
		fishing(i);
		move();
	}

	printf("%d", ans);

	return 0;
}
