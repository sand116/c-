#include <string>
#include <vector>
#include <queue>
#include <iostream>
/*
i :0j : 1
i :1j : 2
i :1j : 3
i :1j : 4
i :1j : 5
i :1j : 6
i :2j : 3
i :2j : 4
i :2j : 5
i :2j : 6
i :3j : 4
i :3j : 5
i :3j : 6
i :4j : 5
i :4j : 6
i :5j : 6
*/
using namespace std;
queue<int>q;
vector<int>discovered;
int bfs(vector<vector<int>>&adj, int des) {
	int here = q.front();
	int cnt = here;
	q.pop();
	while (here != des) {
		for (int i = 0; i < adj[here].size(); i++) {
			if (discovered[adj[here][i]] == -1) {
				discovered[adj[here][i]] = cnt + 1;
				q.push(adj[here][i]);
			}

		}
		here = q.front();
		q.pop();
		cnt = discovered[here];
	}
	return cnt;
}
int main() {
	string begin = "hit";
	string target = "cog";
	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	int answer = 0;
	int des = -1;
	words.insert(words.begin(), begin);

	vector<vector<int>>adj(words.size());
	discovered = vector<int>(words.size(), -1);

	for (int i = 0; i < words.size(); i++) {
		if (words[i] == target) des = i;
		for (int j = i + 1; j < words.size(); j++) {
			bool isAdj = true;
			int k = 0;
			int cnt = 0;
			while (k < words[i].size()) {
				if (words[i][k] != words[j][k]) cnt++;
				if (cnt >= 2) {
					isAdj = false;
					break;
				}
		
				k++;
			}
			if (isAdj) {
				cout << "i :" << i << "j : " << j << endl;
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	if (des == -1) return 0;
	else {
		discovered[0] = 0;
		q.push(0);
		answer = bfs(adj, des);
		return answer;
	}
}