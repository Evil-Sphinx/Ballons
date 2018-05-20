//#include<iostream>
//using namespace std;
//const int MAXV = 510;
//const int INF = 0x7fffffff;
//
//int num[MAXV] = { 0 };
//int w[MAXV] = { 0 };
//int d[MAXV] = { INF };
//int G[MAXV][MAXV] = { INF };
//bool visit[MAXV] = { false };
//int weight[MAXV];
//int main() {
//	int n, m, start, dest;
//	fill(d, d + MAXV, INF);
//	fill(G[0], G[0] + MAXV * MAXV, INF);
//	scanf("%d %d %d %d", &n, &m, &start, &dest);
//
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &weight[i]);
//	}
//	int c1, c2, length;
//	for (int i = 0; i < m; i++) {
//		scanf("%d %d %d", &c1, &c2, &length);
//		G[c1][c2] = G[c2][c1] = length;
//	}
//	d[start] = 0;
//	num[start] = 1;
//	w[start] = weight[start];
//	for (int i = 0; i < n; i++) {
//		int u = -1, MIN = INF;
//		for (int j = 0; j < n; j++) {
//			if (visit[j] == false && d[j] < MIN) {
//				u = j;
//				MIN = d[j];
//			}
//		}
//		if (u == -1)	break;
//		visit[u] = true;
//		for (int v = 0; v < n; v++) {
//			if (visit[v] == false && G[u][v] != INF) {
//				if (d[u] + G[u][v] < d[v]) {
//					d[v] = d[u] + G[u][v];
//					num[v] = num[u];
//					w[v] = w[u] + weight[v];
//				}
//				else if (d[u] + G[u][v] == d[v])
//				{
//					num[v] += num[u];
//					if (w[u] + weight[v] > w[v]) {
//						w[v] = w[u] + weight[v];
//					}
//				}
//			}
//		}
//	}
//	cout << num[dest] << " " << w[dest];
//
//	return 0;
//
//}
