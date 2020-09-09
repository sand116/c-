#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<sstream>
#include <queue>
#include<utility>
using namespace std;
vector<vector<int>>adj;
queue<pair<int,int>> q;
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int total=0;
int N, M;
int day = 0 ;
int cnt = 0;
int wayCnt = 0;
void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		wayCnt = adj[y][x];
		cnt++;
		q.pop();
		for (int way = 0; way < 4; way++) {
			int i = y + direction[way][0];
			int j = x + direction[way][1];
			if (i < 0 || i >= M || j<0 || j>=N) continue;
			if (adj[i][j] == 0) {
				adj[i][j] = adj[y][x] + 1;
				q.push(make_pair(i, j));
			}
		}


	}
	if (cnt != total) cout << -1;
	else cout << wayCnt-1;

	return;
}

int main(void) {
	cin >> N >> M;
	adj = vector<vector<int>>(M, vector<int>(N,0));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj[i][j];
			if (adj[i][j] != -1) total++;
			if (adj[i][j] == 1) q.push(make_pair(i, j));		
			}
	}

	if (!q.empty()) bfs();
	

}
