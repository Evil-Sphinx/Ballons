#include<iostream>
#include<algorithm>
using namespace std;

const int MAXV = 1010;
int G[MAXV][MAXV] = { 0 };
bool visit[MAXV] = { false };

// 深度优先
void dfs(int city, int n) {
	visit[city] = true;
	for (int i = 1; i <= n; i++) {
		if (G[city][i] == 1 && visit[i] == false) {
			dfs(i, n);
		}
	}
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int c1, c2;

	while (m--) {
		cin >> c1 >> c2;
		G[c1][c2] = G[c2][c1] = 1;
	}
	int city;
	while (k--) {
		int cnt = 0;
		cin >> city;
		fill(visit, visit + MAXV, false);
		visit[city] = true;
		for (int i = 1; i <= n; i++) {
			if (false == visit[i]) {
				cnt++;
				dfs(i, n);
			}
		}
		cout << cnt - 1 << endl;
	}
	return 0;
}