#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
vector<vector<int>>adj;
vector<vector<int>>visited;//행렬로 인접리스트 표현
vector<int> tcase;
int cnt = 0;
int T;
int M, N, K;
void dfs(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) return;
	else if (adj[y][x] == 1 && visited[y][x] == false) {
		visited[y][x] = true;
		dfs(y, x-1);
		dfs(y+1, x);
		dfs(y-1, x);
		dfs(y, x + 1);
	}
	return;
}

int main() {
	int x, y;
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> M >> N >> K;
		adj = vector<vector<int>>(N, vector<int>(M, 0));
		visited = vector<vector<int>>(N, vector<int>(M, false));

		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			adj[y][x] = 1;
		}
		cnt = 0;
		for (int i = 0; i < adj.size(); i++) {
			for (int j = 0; j < adj[i].size(); j++) {

				if (adj[i][j] == 1 && visited[i][j] == false)
				{
					dfs(i, j);
					cnt++;
				}

			}
		}
		tcase.push_back(cnt);
	}
	for (int i = 0; i < tcase.size(); i++) {
		cout << tcase[i] << endl;
	}
	return 0;

}