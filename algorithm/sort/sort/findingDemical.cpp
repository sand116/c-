

/* ����Ž������ ã�� ��� - ���� ������ ���ڸ� ������
1���� Ž���Ѵ�.
���� ������ ã�� ���
-  1,2,3���� ���� �� �ִ� ��� ������ ã�� �� 123���� ���� �� �ִ� ���� ū �� �� 321�� ã����ȴ�.
	1���� Ž���Ͽ� ���� ���ǿ� �����ϴ� ��쿡 �ش��ϸ� ����.
	�̸� ���ڿ��� ����� Ž���ϸ� ���� ���� 0321 00321�� ���� �������� �ʾƵ� �ȴٴ� ��. -> stoi �Լ� �̿�
	���� 321�� Ž���ϸ� ��.
	���հ� ������ ����� �Ǹ� -> �� ������ ã�� �� ���� ���� �ÿ� ������ ������ �ڵ尡 �ǰ� ���� �ɸ�.. 

*/
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string.h>
using namespace std;
int check(int number) {
	for (int i = 2; i <= sqrt(number); i++) {
		if (number%i == 0) return 0;
	}
	return 1;
}
int solution(string numbers) {
	vector<int>visited;
	int sum = 0;
	sort(numbers.begin(), numbers.end(), greater<int>());
	int a = stoi(numbers);
	bool isContain;
	for (int i = 2; i <= a; i++) {
		string b = to_string(i);
		visited = vector<int>(numbers.size(), 0);
		for (auto x : b) {
			isContain = false;
			for (int j = 0; j < numbers.size(); j++) {
				// ��ȯ���� char ���� 1�� �̴�. �̶��� ''�� ����ϰ� �̰��� ==�� �����ϴ�.
				if (x == numbers[j] && visited[j] == 0) {
					visited[j] = 1;
					isContain = true;
					break;
				}
			}
			if (!isContain) break;
		}

		if (!isContain) continue;
		if (isContain) {
			cout << i << endl;
			sum += check(i);
		}
	}

	return sum;
}