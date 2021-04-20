#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <limits.h> 
using namespace std;

string str;

void maxCal(int n) {
	if (n % 2 == 1) {
		str += '7';
		n -= 3;

		for (int i = 0; i < n / 2; i++) str += '1';
	}
	else {
		for (int i = 0; i < n / 2; i++) str += '1';
	}
}

long long minval[101] = { 0,0,1,7,4,2,6,8,10 };
string add[8] = { "0", "0", "1", "7", "4", "2", "0", "8" };

void minCal() {
	for (int i = 9; i < 101; i++) {
		for (int j = 2; j < 8; j++) {
			string tmp = to_string(minval[i - j]) + add[j];
			
			minval[i] = min(minval[i], stoll(tmp));
		}
	}
}

int main() {
	for (int i = 9; i < 101; i++) minval[i] = LLONG_MAX;
	minCal();

	int tc, n;

	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> n;
		cout << minval[n] << " ";

		str = "";
		maxCal(n);
		cout << str << "\n";	
	}

	return 0;
}
