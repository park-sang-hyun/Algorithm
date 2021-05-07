#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct MAN {
	int age;
	string name;
	int num;
};

vector <MAN> v;

int n;

bool cmp(MAN& a, MAN& b) {
	if (a.age < b.age) return true;
	else if (a.age == b.age && a.num < b.num) return true;

	return false;
}

int main() {
	fastio;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		string b;

		cin >> a >> b;

		v.push_back({ a, b, i });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) cout << v[i].age << " " << v[i].name << "\n";
	
	return 0;
}
