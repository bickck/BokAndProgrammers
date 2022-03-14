#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void solution() {
	int n, x, y;
	vector<pair<int, int>> peoples;
	vector<int> ranks;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		peoples.push_back({ x,y });
		ranks.push_back(1);
	}

	for (int i = 0; i < n; i++) {

		pair<int, int> target = peoples[i];
		for (int j = 0; j < i; j++) {
			pair<int,int> comp = peoples[j];
			if (target.first < comp.first && target.second < comp.second) {
				ranks[i]++;
			}
			if (target.first > comp.first && target.second > comp.second) {
				ranks[j]++;
			}
		}
	}

	for (int i = 0; i < ranks.size(); i++) {
		cout << ranks[i] <<" ";
	}

}

int main() {

	solution();

	return 0;
}