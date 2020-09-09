

/* 완전탐색으로 찾는 경우 - 백퍼 한정된 숫자를 제공함
1부터 탐색한다.
숫자 조합을 찾는 경우
-  1,2,3으로 만들 수 있는 모든 조합을 찾을 때 123으로 만들 수 있는 가장 큰 수 즉 321을 찾으면된다.
	1부터 탐색하여 위의 조건에 만족하는 경우에 해당하면 리턴.
	이를 문자열로 만들어 탐색하면 좋은 점으 0321 00321을 내가 구분하지 않아도 된다는 점. -> stoi 함수 이용
	위는 321번 탐색하면 됨.
	조합과 순열로 만들게 되면 -> 각 조합을 찾은 후 순열 했을 시에 굉장히 복잡한 코드가 되고 오래 걸림.. 

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
				// 반환형이 char 문자 1개 이다. 이때는 ''을 사용하고 이것은 ==비교 가능하다.
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