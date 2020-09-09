#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<sstream>
#include <queue>
#include<utility>
using namespace std;
vector<vector<vector<int>>>adj;
queue<pair<int,pair<int, int>>> q;
int direction[6][3] = { {-1,0,0},{1,0,0},{0,-1,0},{0,1,0}, {0,0,-1},{0,0,1} };
int total = 0;
int N, M, H ;
int day = 0;
int cnt = 0;
int wayCnt = 0;
void bfs() {
	while (!q.empty()) {
		int h = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		wayCnt = adj[h][y][x];
		cnt++;
		q.pop();
		for (int way = 0; way < 6; way++) {
			int i = y + direction[way][0];
			int j = x + direction[way][1];
			int k = h + direction[way][2];
			if (i < 0 || i >= N || j < 0 || j >= M || k<0 || k>= H) continue;
			if (adj[k][i][j] == 0) {
				adj[k][i][j] = adj[h][y][x] + 1;
				q.push(make_pair(k,make_pair(i, j)));
			}
		}


	}
	if (cnt != total) cout << -1;
	else cout << wayCnt - 1;

	return;
}

int main(void) {
	cin >> M >> N >> H;
	adj = vector<vector<vector<int>>>(H, vector<vector<int>>(N, vector<int>(M, 0)));
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> adj[h][n][m];
				if (adj[h][n][m] != -1) total++;
				if (adj[h][n][m] == 1) q.push(make_pair(h, make_pair(n, m)));
			}
		}
	}
	if (!q.empty()) bfs();
}
