#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int a, p;

vector <int> vec;
map <int, int> v;

int trans(int a) {
	int sum = 0;

	while (a > 0) {
		sum += pow(a % 10, p);
		a /= 10;
	}

	vec.push_back(sum);
	if (v.find(sum) != v.end()) v[sum]++;
	else v[sum] = 1;

	return sum;
}

int check(int sum) {
	if (v[sum] > 1) return sum;

	return -1;
}

int main() {
	fastio;

	cin >> a >> p;
	vec.push_back(a);
	v[a] = 1;

	while (1) {
		a = trans(a);

		int cut = check(a);
		if (cut != -1) {
			int cnt = 0;

			for (int i = 0; i < vec.size(); i++) {
				if (vec[i] == cut) break;
				cnt++;
			}
			
			cout << cnt;
			break;
		}
	}

	return 0;
}
