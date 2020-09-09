#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;
//백트래킹 추가해야함

vector<string> answer;
map<string, vector<string>>m;
map<string, vector<string>>sorted_m;
map<string, vector<int>>visited;

void dfs(string key, int size) {
	answer.push_back(key);
	if
	if (answer.size() == size * 2 - (size - 1)) return;
	int cnt = 0;
	for (auto x : sorted_m[key]) {

		if (visited[key][cnt] == 0) {
			visited[key][cnt] = 1;
			dfs(x, size);
		}
		cnt++;
	}
	return;
}
void main() {
	vector<vector<string>> tickets = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} };
	for (int i = 0; i < tickets.size(); i++) {
		m[tickets[i][0]].push_back(tickets[i][1]);
	}


	for (auto x : m) {
		sort(x.second.begin(), x.second.end());
		visited[x.first] = vector<int>(x.second.size(), 0);
		sorted_m[x.first] = x.second;
		cout << endl;
	}

	dfs("ICN", tickets.size());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] <<" ";
	}
}