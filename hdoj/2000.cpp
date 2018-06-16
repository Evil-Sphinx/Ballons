#include<cstdio>

int main() {
	char a[3];
	while (scanf("%c %c %c", &a[0], &a[1], &a[2]) != EOF) {
		if (a[0] > a[1]) {
			a[0] = a[0] ^ a[1];
			a[1] = a[0] ^ a[1];
			a[0] = a[0] ^ a[1];
		}
		if (a[0] > a[2]) {
			a[0] = a[0] ^ a[2];
			a[2] = a[0] ^ a[2];
			a[0] = a[0] ^ a[2];
		}

		if (a[1] > a[2]) {
			a[1] = a[1] ^ a[2];
			a[2] = a[1] ^ a[2];
			a[1] = a[1] ^ a[2];
		}
		printf("%c %c %c\n", a[0], a[1], a[2]);
		getchar();
	}
	return 0;
}
