#include<iostream>
#include<vector>
using namespace std;

const int MAXV = 201;

int G[MAXV][MAXV] = { 0 };

int Nv, Ne;

//判断是否为Clique 
bool judgeClique(vector<int> &v) {
	int size = v.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (G[v[i]][v[j]] == 0)	return false;
		}
	}
	return true;
}

//判断是否为MaxmialClique 
bool judgeMaxmial(vector<int> &v) {
	vector<int> tmp;
	for (int i = 1; i <= Nv; i++) {
		if (G[v[0]][i])	tmp.push_back(i);		//找出其中一个点所有相邻的点 
	}
	vector<int> cnt(Nv + 1);
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < tmp.size(); j++) {
			if (G[v[i]][tmp[j]])		cnt[tmp[j]]++;
		}
	}
	for (int i = 1; i < Nv; i++) {
		if (cnt[i] == (v.size() - 1)) {

			if (v.size() == 1 && tmp.size() == 1) {
				return true;
			}
			else {
				return false;
			}

		}

	}

	return true;
}

int main() {
	int v1, v2;
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
			if (judgeMaxmial(v)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "Not Maxmial" << endl;
			}
		}
		else {
			cout << "Not a Clique" << endl;
		}

	}
	return 0;
}