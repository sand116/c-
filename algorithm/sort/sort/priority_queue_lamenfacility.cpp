#include <string>
#include <vector>
#include <queue> 
//우선순위 큐를 이용할 때 사용 - 그냥 fifo 큐의 상황에서는 deque사용해도 무관하다.
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	priority_queue<int, vector<int>, less<int>> q; //vector컨테이너를 이용함, less -최대힙 
	// push, pop , top() -> 스택에서는 last값/ 큐에서는 first값을 의미 
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