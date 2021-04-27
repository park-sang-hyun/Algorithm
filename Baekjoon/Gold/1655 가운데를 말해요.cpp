#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

priority_queue <int> maxq;
priority_queue <int> minq;

int n;

int main() {
	fastio;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;

		if (maxq.size() > minq.size()) minq.push(-k); 
		else maxq.push(k);

		if (!maxq.empty() && !minq.empty() && maxq.top() > -minq.top()) {
			int maxt = maxq.top();
			int mint = -minq.top();

			maxq.pop();
			minq.pop();

			maxq.push(mint);
			minq.push(-maxt);
		}

		cout << maxq.top() << "\n";
	}
	
	return 0;
}
