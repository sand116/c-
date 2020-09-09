#include <iostream>;
#include <vector>;
#include <string>;
#include <queue>;
#include <utility>;
using namespace std;
vector<vector<int>>adj;
vector<vector<int>>discovered;
queue<pair<int,int>> q;
int N, M;
int xDirection[4] = {-1, 0, 1, 0};
int yDirection[4] = { 0, 1, 0, -1 };

void bfs(int y, int x) {
	discovered[y][x] = true;
	q.push(make_pair(y, x));

		while (!q.empty()) {
			pair<int, int> here = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int y = here.first + yDirection[i];
				int x = here.second + xDirection[i];
				if (y >= N || x < 0 || x >= M || y < 0) continue;
				if (!discovered[y][x] && adj[y][x]) {
					discovered[y][x] = discovered[here.first][here.second]+1;
					q.push(make_pair(y, x));

				}
				
			}
		}

		return;
}
int main(void) {
	cin >> N >> M;
	adj = vector<vector<int>>(N, vector<int>(M,0));
	discovered = vector<vector<int>>(N, vector<int>(M,0));

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < row.size(); j++) {
			adj[i][j] = row[j] - '0';
		}
	}
	bfs(0, 0);
	cout<<discovered[N-1][M-1];

}
