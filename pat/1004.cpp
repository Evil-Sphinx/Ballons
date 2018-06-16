#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> v[100];

int level[100], book[100];
int maxlevel = -1;

void bfs() {
	queue<int> q;
	q.push(1);
	level[1] = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		maxlevel = max(maxlevel, level[node]);
		if (v[node].size() == 0) {
			book[level[node]]++;
		}
		else {
			for (int i = 0; i < v[node].size(); i++) {
				int id = v[node][i];
				level[id] = level[node] + 1;
				q.push(id);
			}
		}
	}
}

int main() {
	int n, m, node, k, child;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &node, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			v[node].push_back(child);
		}
	}
	bfs();
	printf("%d", book[0]);
	for (int i = 1; i <= maxlevel; i++) {
		printf(" %d", book[i]);
	}
	return 0;
}
