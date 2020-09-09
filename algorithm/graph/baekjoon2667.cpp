#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<sstream>
using namespace std;
vector<vector<int>>adj;
vector<vector<int>>visited;
vector<int>number;
int N;
int cnt;
int group=0;
void dfs(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) return ;
	else if (adj[x][y] == 1 && visited[x][y] == -1) {
		visited[x][y] = 1;
		cnt++;
		dfs(x - 1, y);
		dfs(x + 1 , y);
		dfs(x , y - 1);
		dfs(x , y + 1);
	}

	return ;

}

int main() {
	cin >> N;
	adj = vector< vector<int> >(N,vector<int>(N,0));
	visited = vector< vector<int> >(N, vector<int>(N, -1));
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			adj[i][j] = temp[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt = 0;
			if (adj[i][j] == 1 & visited[i][j] == -1) {
				dfs(i, j);
				group++;
				number.push_back(cnt);
			}
		}
	}
	sort(number.begin(), number.end());
	cout << group<<endl;
	for (int i = 0; i < number.size(); i++) {
		cout << number[i]<<endl;

	}
	return 0;
}
