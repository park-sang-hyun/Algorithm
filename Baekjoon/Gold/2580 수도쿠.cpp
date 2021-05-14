#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int sd[9][9], v[81][2], c;

void go(int cnt) {
	if (cnt == c) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) printf("%d ", sd[i][j]);
			puts("");
		}

		exit(0);
	}
	
	int y = v[cnt][0];
	int x = v[cnt][1];
	int ty, tx;
	int ch[10] = { 0, 0,0,0,0,0,0,0,0,0 };

	for (int i = 0; i < 9; i++) {
		ch[sd[i][x]] = 1;
		ch[sd[y][i]] = 1;
	}

	if (y >= 0 && y < 3) ty = 0;
	else if (y >= 0 && y < 6) ty = 3;
	else ty = 6;

	if (x >= 0 && x < 3) tx = 0;
	else if (x >= 0 && x < 6) tx = 3;
	else tx = 6;
	
	for (int i = ty; i < ty + 3; i++)
		for (int j = tx; j < tx + 3; j++) ch[sd[i][j]] = 1;
		
	for (int i = 0; i < 10; i++) 
		if (ch[i] == 0) {
			sd[y][x] = i;
			go(cnt + 1);
			sd[y][x] = 0;
		}
}

int main(){
	for(int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			scanf("%d", &sd[i][j]);
			if (sd[i][j] == 0) {
				v[c][0] = i;
				v[c][1] = j;
				c++;
			}
		}
		
	go(0);

	return 0;
}
