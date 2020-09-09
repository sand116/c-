#include <string>
#include <vector>
#include <iostream>

/*
��� �����̳ʸ� ��������� �������� �� �����̳ʸ� ������ ��� �۾����� ���� �ϳĿ� �޷��ֽ��ϴ�.

�Ϲ����� ��Ȳ������ �׳� ���͸� ����Ѵ� (���� �����̴�!)

���࿡ �� ���� �ƴ� �߰��� ���ҵ��� �߰��ϰų� �����ϴ� ���� ���� �ϰ�, ���ҵ��� ���������θ� ���� �Ѵٸ� ����Ʈ�� ����Ѵ�.
-insert, find, erase ��� 

���࿡ �� ó���� �� ��ο� ���ҵ��� �߰��ϴ� �۾��� �����ϸ� ���� ����Ѵ�.

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