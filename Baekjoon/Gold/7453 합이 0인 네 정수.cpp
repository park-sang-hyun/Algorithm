#include <cstdio>
typedef long long ll;

int n, A[4000], B[4000], C[4000], D[4000], AA[16000000], BB[16000000],T[16000000];

void MS(int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		MS(l, mid);
		MS(mid + 1, r);
		int a = l, b = mid + 1, total = l;
		while (a <= mid && b <= r) {
			if (AA[a] < AA[b]) T[total++] = AA[a++];
			else T[total++] = AA[b++];
		}
		while(a <= mid) T[total++] = AA[a++];
		while(b <= r) T[total++] = AA[b++];
		for (int i = l; i <= r; i++) AA[i] = T[i];
	}
}

int BSL(int target, int low, int high) {
	while (low < high) {
		int mid = (low + high) / 2;

		if ((ll)(AA[mid] + target) < 0) low = mid + 1;
		else high = mid;
	}

	return high + 1;
}

int BSU(int target, int low, int high) {
	while (low < high) {
		int mid = (low + high) / 2;

		if ((ll)(AA[mid] + target) <= 0) low = mid + 1;
		else high = mid;
	}

	return high + 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	
	int c = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			AA[c] = A[i] + B[j];
			BB[c++] = C[i] + D[j];
		}

	MS(0, n * n - 1);

	ll sum = 0;
	for (int i = 0; i < n * n; i++) 
		sum += BSU(BB[i], 0, n * n) - BSL(BB[i], 0, n * n);
	

	printf("%lld", sum);

	return 0;
}
