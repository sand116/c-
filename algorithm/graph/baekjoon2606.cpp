#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<vector<int>>adj;
vector<int>visited;
int cnt = -1;
int dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		int there = adj[v][i];

		if (!visited[there]) {
			cnt =+ dfs(there);
		}
	}

	return cnt+1 ;
}
int main() {
	int V, N;
	int node1, node2;
	cin >> V;
	cin >> N;
	adj = vector<vector<int>>(V + 1);
	visited = vector<int>(V+1,false);
	for (int i = 0; i < N; i++) {
		cin >> node1 >> node2;
		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
	}
	cout<< dfs(1);

}