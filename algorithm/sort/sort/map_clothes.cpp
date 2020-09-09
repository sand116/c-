#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
/*
데이터의 존재 유무 만 궁금할 경우 → set

중복 데이터를 허락할 경우 → multiset (insert, erase, find 모두 O(\log N)O(logN). 최악의 경우에도 O(\log N)O(logN))

데이터에 대응되는 데이터를 저장하고 싶은 경우 → map

중복 키를 허락할 경우 → multimap (insert, erase, find 모두 O(\log N)O(logN). 최악의 경우에도 O(\log N)O(logN))

속도가 매우매우 중요해서 최적화를 해야하는 경우 → unordered_set, unordered_map
(insert, erase, find 모두 O(1)O(1). 최악의 경우엔 O(N)O(N) 그러므로 해시함수와 상자 개수를 잘 설정해야 한다!)

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