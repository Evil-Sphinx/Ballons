#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;


struct Stu {
	string id;
	int scores[4];
	int ranks[4];
};
int main() {
	char type[4] = { 'A','C','M','E' };
	int n, m;
	cin >> n >> m;
	vector<Stu> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].id;
		float sum = 0;
		for (int j = 1; j <= 3; j++) {
			cin >> v[i].scores[j];
			sum += v[i].scores[j];
		}
		v[i].scores[0] = sum / 3 + 0.5;
	}

	for (int j = 0; j < 4; j++) {
		sort(v.begin(), v.end(), [j](Stu a, Stu b)->bool {return a.scores[j] > b.scores[j]; });
		v[0].ranks[j] = 1;
		for (int i = 1; i < v.size(); i++) {
			if (v[i].scores[j] == v[i - 1].scores[j]) {
				v[i].ranks[j] = v[i - 1].ranks[j];
			}
			else {
				v[i].ranks[j] = i + 1;
			}
		}
	}

	//sort(v.begin(), v.end(), [](Stu a, Stu b) {return a.id < b.id; });


	//打表法
	map<string, int> _map;
	for (int i = 0; i < v.size(); i++) {
		_map.insert(make_pair(v[i].id, i));
	}
	while (m--) {
		string id;
		cin >> id;

		auto it= _map.find(id);
		if (it != _map.end()) {
			int index = it->second;
			int min = v[index].ranks[0];
			int pos = 0;
			for (int i = 1; i < 4; i++) {
				if (v[index].ranks[i] < min) {
					min = v[index].ranks[i];
					pos = i;
				}
			}
			cout << min << " " << type[pos] << endl;
		}
		else {
			cout << "N/A" << endl;
		}

		//二分法
		//bool flag = true;
		//int left = 0, right = n - 1;
		//while (left <= right) {
		//	int mid = (left + right) / 2;
		//	if (v[mid].id == id) {
		//		flag = false;
		//		int min = v[mid].ranks[0];
		//		int index = 0;
		//		for (int i = 1; i < 4; i++) {
		//			if (v[mid].ranks[i] < min) {
		//				min = v[mid].ranks[i];
		//				index = i;
		//			}
		//		}
		//		cout << min << " " << type[index] << endl;
		//		break;
		//	}
		//	else if (v[mid].id > id) {
		//		right = mid - 1;
		//	}
		//	else
		//	{
		//		left = mid + 1;
		//	}
		//}
		//if (flag) {
		//	cout << "N/A" << endl;
		//}

		//暴力法
		//bool flag = true;
		//for (auto it = v.begin(); it != v.end(); it++) {
		//	if (it->id == id) {
		//		flag = false;
		//		int min = it->ranks[0];
		//		int index = 0;
		//		for (int j = 1; j < 4; j++) {
		//			if (it->ranks[j] < min) {
		//				min = it->ranks[j];
		//				index = j;
		//			}
		//		}
		//		cout << min << " " << type[index] << endl;
		//		break;
		//	}
		//}
		//if (flag) {
		//	cout << "N/A" << endl;
		//}
	}

	return 0;
}