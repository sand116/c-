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
		int front = priorities.front();// �� ó�� ��
		if (front == sorted[j]) { // ��ó������ ���� ���� �켱���� �̸�
			answer++;
			if (location == 0) {//�׸��� �� ���� ���ϴ� ���̸�
	// ī��Ʈ�� �����Ѵ�
				return;
			}
			priorities.erase(priorities.begin());//���� 
			location--;//���� ���ϴ� ���� ��ġ�� �����ΰ���.
			j++;// �켱���� ���� �ڷ� ���� �ȴ�.
			cout << "a"<<location << endl;
		}
		else {
			priorities.erase(priorities.begin());//�켱������ �ƴϸ� �׳� ���� �ڷ� �־��ش�.
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