#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
/*
�������� ���� ���� �� �ñ��� ��� �� set

�ߺ� �����͸� ����� ��� �� multiset (insert, erase, find ��� O(\log N)O(logN). �־��� ��쿡�� O(\log N)O(logN))

�����Ϳ� �����Ǵ� �����͸� �����ϰ� ���� ��� �� map

�ߺ� Ű�� ����� ��� �� multimap (insert, erase, find ��� O(\log N)O(logN). �־��� ��쿡�� O(\log N)O(logN))

�ӵ��� �ſ�ſ� �߿��ؼ� ����ȭ�� �ؾ��ϴ� ��� �� unordered_set, unordered_map
(insert, erase, find ��� O(1)O(1). �־��� ��쿣 O(N)O(N) �׷��Ƿ� �ؽ��Լ��� ���� ������ �� �����ؾ� �Ѵ�!)

*/
using namespace std;
vector<pair<string, vector<string>>> a;
bool existed;
int main(void) {
	vector<vector<string>> clothes = {{"yellow_hat", "headgear"}, { "blue_sunglasses", "eyewear" }, { "green_turban", "headgear" }};
	int answer = 1;
	for (int i = 0; i < clothes.size(); i++) {
		existed = false;
		if (!a.empty()) {
			for (int j = 0; j < a.size(); j++) {
				if (clothes[i][1] == a[j].first) {
					(a[j].second).push_back(clothes[i][0]);
					existed = true;
					break;
				}
			}
		}
		if (!existed) {
			
				a.push_back(make_pair(clothes[i][1], vector<string>(1, clothes[i][0])));
			}
		}
	for (int i = 0; i < a.size(); i++) {
		answer *= (a[i].second.size()+1);
	}
	cout<< answer - 1;
	return 0;
}