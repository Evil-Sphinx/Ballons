#include<iostream>

#define MAXN 1005

using namespace std;
float poly[MAXN] = { 0.0 };

int main() {
	int k;
	int ex;
	float co;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> ex >> co;
		poly[ex] += co;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> ex >> co;
		poly[ex] += co;
	}
	int total = 0;
	for (int i = 0; i < MAXN; i++) {
		if (poly[i] > 0)	total++;
	}
	printf("%d", total);
	for (int i = MAXN - 1; i >= 0; i--) {
		if (poly[i]) {
			printf(" %d %.1f", i, poly[i]);
		}
	}
	return 0;
}
