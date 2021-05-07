#include <iostream>
#include <vector>
#include <string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string s, w;
int slen, wlen, v[52], ans;

bool check() {
	for (int i = 0; i < 52; i++) 
		if(v[i] != 0) return false;

	return true;
}

int main() {
	fastio;

	cin >> wlen >> slen;
	cin >> w >> s;

	for (int i = 0; i < wlen; i++) {
		if(w.at(i) >= 'A' && w.at(i) <= 'Z') v[w.at(i) - 'A']++;
		else v[w.at(i) - 'a' + 26]++;
	}

	for (int i = 0; i <= slen - wlen; i++) {
		if (i == 0) {
			for (int j = i; j < i + wlen; j++) {
				if (s.at(j) >= 'A' && s.at(j) <= 'Z') v[s.at(j) - 'A']--;
				else v[s.at(j) - 'a' + 26]--;
			}
		}
		else {
			if (s.at(i - 1) >= 'A' && s.at(i - 1) <= 'Z') v[s.at(i - 1) - 'A']++;
			else v[s.at(i - 1) - 'a' + 26]++;

			if (s.at(i + wlen - 1) >= 'A' && s.at(i + wlen - 1) <= 'Z') v[s.at(i + wlen - 1) - 'A']--;
			else v[s.at(i + wlen - 1) - 'a' + 26]--;
		}

		if(check()) ans++;
	}
	
	cout << ans;

	return 0;
}
