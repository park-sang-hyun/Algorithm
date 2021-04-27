#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct point {
	int a1 = -1, a2 = -1;
}P[800005];

int w, n, s[5001];

bool ok = false;


int main() {
	fastio;

	cin >> w >> n;
	for (int i = 0; i < n; i++) cin >> s[i];

	sort(s, s + n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] + s[j] < w) {
				P[s[i] + s[j]].a1 = i;
				P[s[i] + s[j]].a2 = j;
			}
		}
	}

	for (int j = 2; j < n; j++) {
		for (int k = j + 1; k < n; k++) {
			int id = w - (s[j] + s[k]);

			if (id < 0) continue;
			if (P[id].a1 != -1 && P[id].a2 != -1) {
				if (P[id].a1 != j && P[id].a1 != k && P[id].a2 != j && P[id].a2 != k) {
					cout << "YES";
					return 0;
				}
			}
		}
	}

	cout << "NO";
	return 0;
}
