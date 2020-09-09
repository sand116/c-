#include <algorithm>;
#include <iostream>;
#include <vector>;
#include <string>;
using namespace std;

vector<vector<int>> adj;
vector<int> seen, order;
vector<string> words;

void dfs(int here) {
	seen[here] = 1;
	for (int there = 0; there < adj.size(); ++there) {
		if (adj[here][there] && !seen[there])
			dfs(there);
	}
	order.push_back(here);
}

vector<int> topologicalSort() {
	int m = adj.size();
	seen = vector<int>(26, 0);
	order.clear();
	for (int i = 0; i < m; ++i) if (!seen[i]) dfs(i);

	reverse(order.begin(), order.end());
	/*
		�ùٸ� ����Ŭ�� ���� ���� �׷����� �������� ����� �ѹ������� �����Ǵ� ����Ŭ ���� �迭�̴�
		���� �� �������Ŀ� 
		�����ϴ� ������ �׷����� �����Ѵٸ� ����Ŭ�� �ִ� �׷������ �ǹ��̴�. 

	*/

	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			if (adj[order[j]][order[i]]) return vector<int>();
		}
	}
	return order;
}

void makeGraph(const vector<string>&words) {
	adj = vector<vector<int>>(26, vector<int>(26,0)); 
	for (int i = 1; words.size(); ++i) {
		int j = i - 1;
		int len = min(words[i].size(), words[j].size());

		for (int cnt = 0 ; cnt < len  ; cnt++ ){
			if (words[i][cnt] != words[j][cnt]) {
				int next = words[i][cnt] - 'a';
				int front = words[j][cnt] - 'a';
				adj[next][front] = 1;
				break;
			}
		}
		
	}
}
void main() {
	int N, M;
	cin >> N;
	for (int cnt = 0; cnt < N; ++cnt) {
		cin >> M;
		cin.ignore();
		words = vector<string>(M);
		for (int cnt = 0; cnt < M; ++cnt) {
			getline(cin, words[cnt]);
		}

		makeGraph(words);
		for (int i = 0; i < order.size(); i++) {
			cout << order[i] << " ";
		}
		cout << endl;

	}
	return;

}