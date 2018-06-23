#include<iostream>
#include<vector>
using namespace std;

const int MAXV = 201;

int G[MAXV][MAXV] = { 0 };

//ÅÐ¶ÏÊÇ·ñÎªClique 
bool judgeClique(vector<int> &v) {
	int size = v.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (G[v[i]][v[j]] == 0)	return false;
		}
	}
	return true;
}

int main() {
	int Nv, Ne, v1, v2;
	scanf("%d %d", &Nv, &Ne);
	for (int i = 1; i <= Ne; i++) {
		scanf("%d %d", &v1, &v2);
		G[v1][v2] = G[v2][v1] = 1;
	}
	int m;
	scanf("%d", &m);
	int k;
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		vector<int> v(k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &v[j]);
		}
		if (judgeClique(v)) {
			cout << "Yes";
		}
		else {
			cout << "Not a Clique";
		}

	}
	return 0;
}
