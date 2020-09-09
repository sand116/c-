#include <string>
#include <vector>
#include <iostream>
using namespace std;
void main() {
	vector<vector<int>> baseball = { {123, 1, 1},
									{356, 1, 0},
									{327, 2, 0},
									{489, 0, 1} };
	vector<int>a(3, 0);
	vector<int>b(3, 0);
	int strike = 0;
	int ball = 0;
	int answer = 0;
	int num;
	int cnt = 0;

	for (int n = 111; n < 400; n++) {
		strike = 0;
		ball = 0;
		a[0] = n / 100;
		a[1] = (n % 100) / 10;
		a[2] = ((n % 100) % 10);
		if (a[0] == 0 or a[1] == 0 or a[2] == 0) continue;
		for (int i = 0; i < baseball.size(); i++) {
			strike = 0;
			ball = 0;
			num = baseball[i][0];
			b[0] = num / 100;
			b[1] = (num % 100) / 10;
			b[2] = ((num % 100) % 10);
			for (int i = 0; i < a.size(); i++) {
				for (int j = 0; j < b.size(); j++) {
					if (i == j && a[i] == b[j]) strike++;
					if (i != j && a[i] == b[j]) ball++;
				}
			}
			if (strike == baseball[i][1] && ball == baseball[i][2]) cnt++;
		}
		if (cnt == baseball.size()) answer++;
	}
	

	cout << answer;
	return;
	}

	