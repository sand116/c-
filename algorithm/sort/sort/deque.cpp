#include <string>
#include <vector>
#include <iostream>

/*
어떠한 컨테이너를 사용할지는 전적으로 이 컨테이너를 가지고 어떠한 작업들을 많이 하냐에 달려있습니다.

일반적인 상황에서는 그냥 벡터를 사용한다 (거의 만능이다!)

만약에 맨 끝이 아닌 중간에 원소들을 추가하거나 제거하는 일을 많이 하고, 원소들을 순차적으로만 접근 한다면 리스트를 사용한다.
-insert, find, erase 경우 

만약에 맨 처음과 끝 모두에 원소들을 추가하는 작업을 많이하면 덱을 사용한다.

//push_front / push_back
//pop_front / pop_back
// front() back()

*/
using namespace std;
void main() {
	vector<int> progresses = { 93, 30, 55 };
	vector<int> speeds = { 1, 30, 5 };
	vector<int>::iterator it = progresses.begin();
	vector<int> answer;
	while (it != progresses.end()) {
		int distribution = 0;
		for (int i = 0; i < progresses.size(); i++) {
			progresses[i] += speeds[i];
		}
		while (it!=progresses.end()&& *it >= 100) {
			it++;
			distribution++;
		}
		if (distribution != 0) answer.push_back(distribution);

	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return;
}