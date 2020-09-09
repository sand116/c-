#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

void main() {
	vector<int> priorities = { 1, 1, 9,1,1,1 };
	int location = 0;
	int answer = 0;
	vector<int> sorted = priorities;
	sort(sorted.begin(), sorted.end(), greater<int>());
	int j = 0;
	while (1) {
		int front = priorities.front();// 맨 처음 값
		if (front == sorted[j]) { // 맨처음값이 가장 높은 우선순위 이면
			answer++;
			if (location == 0) {//그리고 그 값이 원하는 값이면
	// 카운트를 리턴한다
				return;
			}
			priorities.erase(priorities.begin());//뺀다 
			location--;//빼면 원하는 값의 위치가 앞으로간다.
			j++;// 우선순위 값은 뒤로 가게 된다.
			cout << "a"<<location << endl;
		}
		else {
			priorities.erase(priorities.begin());//우선순위가 아니면 그냥 빼고 뒤로 넣어준다.
			priorities.push_back(front);
			if (location == 0) {
				location = priorities.size() - 1;
				cout << location << endl;
				continue;
			}
			location--;
		}
	}
}