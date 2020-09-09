#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;
bool compare(pair<int, int> left, pair<int, int> right) {
	if (left.first > right.first) {
		return true;
	}
	else if (left.first == right.first) {
		if (left.second < right.second) {
			return true;
		}
	}
	return false;
}

void main() {
	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays = { 500, 600, 150, 800, 2500 };
	vector<int> answer;

	//unordered_map 삽입 ,찾기, 삭제가 o(1) and 순서가 없음. 대신 sort안됨 -> insert,erase,find 지원 <-> vector는 insert, erase o(n)
	//map - 순서 존재/ 자기만의 기준으로 sort함 : 기본 less<int> 
	unordered_map<string, int> summap;// key가 string
	unordered_map<string, vector<pair<int, int>>> genmap;// key가 string value가 vector


	for (int i = 0; i < genres.size(); i++) {
		summap[genres[i]] += plays[i]; //v존재하면 기존 value에 더한다. 존재하지 않으면 key,value를 새로 생성하고 값을 대입한다
		genmap[genres[i]].push_back(make_pair(plays[i], i));//존재하지 않으면 새로 생성해서 push한다. 존재하면 그냥 푸쉬한다.
	}
	vector<pair<int, string>> fororder; // unordered_map은 sort를 지원하지 않으므로 vector로 옮겨서 sort한다.

	for (auto x : summap) {
		fororder.push_back(make_pair(x.second, x.first));
	}
	sort(fororder.begin(), fororder.end());//sum기준으로 sort함 -> 원소가 pair일때는 first값을 기준으로 sort함

	while (fororder.size() > 0) {
		pair<int, string> temp = fororder.back();//뒤 값 참조 - front()/back() <-> 큐,스택
		fororder.pop_back();// 큰 값 뽑아냄 
		vector<pair<int, int>> a = genmap[temp.second];
		sort(a.begin(), a.end(), compare);
		int lastn = 2;
		if (a.size() < 2) {
			lastn = a.size();
		}
		for (int i = 0; i < lastn; i++) {
			answer.push_back(a[i].second);
		}
		vector<pair<int, int>>().swap(a);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout<<answer[i];
}
}
