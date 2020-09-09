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

	//unordered_map ���� ,ã��, ������ o(1) and ������ ����. ��� sort�ȵ� -> insert,erase,find ���� <-> vector�� insert, erase o(n)
	//map - ���� ����/ �ڱ⸸�� �������� sort�� : �⺻ less<int> 
	unordered_map<string, int> summap;// key�� string
	unordered_map<string, vector<pair<int, int>>> genmap;// key�� string value�� vector


	for (int i = 0; i < genres.size(); i++) {
		summap[genres[i]] += plays[i]; //v�����ϸ� ���� value�� ���Ѵ�. �������� ������ key,value�� ���� �����ϰ� ���� �����Ѵ�
		genmap[genres[i]].push_back(make_pair(plays[i], i));//�������� ������ ���� �����ؼ� push�Ѵ�. �����ϸ� �׳� Ǫ���Ѵ�.
	}
	vector<pair<int, string>> fororder; // unordered_map�� sort�� �������� �����Ƿ� vector�� �Űܼ� sort�Ѵ�.

	for (auto x : summap) {
		fororder.push_back(make_pair(x.second, x.first));
	}
	sort(fororder.begin(), fororder.end());//sum�������� sort�� -> ���Ұ� pair�϶��� first���� �������� sort��

	while (fororder.size() > 0) {
		pair<int, string> temp = fororder.back();//�� �� ���� - front()/back() <-> ť,����
		fororder.pop_back();// ū �� �̾Ƴ� 
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
