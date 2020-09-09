#include <string>
#include <vector>
#include <queue> 
//�켱���� ť�� �̿��� �� ��� - �׳� fifo ť�� ��Ȳ������ deque����ص� �����ϴ�.
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	priority_queue<int, vector<int>, less<int>> q; //vector�����̳ʸ� �̿���, less -�ִ��� 
	// push, pop , top() -> ���ÿ����� last��/ ť������ first���� �ǹ� 
	int j = 0;
	int answer = 0;
	for (int i = 0; i < k; i++) {
		if (i == dates[j]) {
			q.push(supplies[j]);
			j++;
		}
		if (stock == 0) {
			stock += q.top();
			q.pop();
			answer++;
		}
		stock--;

	}

	return answer;
}