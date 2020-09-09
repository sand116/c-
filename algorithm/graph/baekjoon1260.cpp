#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
using namespace std;

vector<vector<int>>adj;
vector<bool>visited;
vector<bool>discovered;
queue<int>q;
vector<int>dfsOrder;
vector<int>bfsOrder;
//dfs,bfs 함수
//입력은 main 에서 받기


void dfs(int v) {
	visited[v] = true;
	dfsOrder.push_back(v);
	if (!adj[v].empty()) 
	{
		for (vector<int>::size_type i = 0; i < adj[v].size(); i++) {
			if (visited[adj[v][i]]== false) dfs(adj[v][i]);
		}
	}
	return;
}
	

void bfs(int v) {
	discovered[v] = true;
	q.push(v);
	while (!q.empty()) {
		int here = q.front();
		bfsOrder.push_back(here);
		q.pop();
		for (vector<int>::size_type i = 0; i < adj[here].size(); i++) {
			if ( discovered[adj[here][i]]==false) {
				discovered[adj[here][i]] = true;
				q.push(adj[here][i]);
			}

		}
	}
	return;
}

int main() {
	int N, M, start;
	cin >> N >> M >> start;
	adj = vector<vector<int>>(N+1);//인접리스트로 표현
	visited = vector<bool>(N + 1,false);
	discovered = vector<bool>(N + 1,false);

	for (int cnt = 0; cnt < M; cnt++) {
		int V1, V2;
		cin >> V1 >> V2;
		adj[V1].push_back(V2);
		adj[V2].push_back(V1);
	}
	for (int i = 1; i < adj.size(); i++) {
		sort(adj[i].begin(),adj[i].end());
	}

	dfs(start);
	bfs(start);


	for (vector<int>::size_type i = 0; i < dfsOrder.size(); i++) {
		cout <<dfsOrder[i]<<" ";
		}
	cout << endl;
	for (vector<int>::size_type i = 0; i < bfsOrder.size(); i++) {
		cout << bfsOrder[i] <<" ";
	}
	return 0;
}