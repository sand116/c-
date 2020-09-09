#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

//부분집합 구하기 

//1. 부분집합 개수가 정해지지 않은 경우 - 모든 부분집합의 개수를 구하기

//for문 안에 재귀가 선언된 경우 
//for문 안에 재귀가 선언되지 않은 경우 
using namespace std;
vector<vector<string>> retArray;
vector<string> str;
vector<string> selected;

void combination( vector<string> & selected, int start) {
	selected.push_back(str[start]);//start 값을 넣고
	retArray.push_back(selected);
	// 다음에 결합될 집합들을 찾아나선다.
	for (int i = start+1; i < str.size(); i++) combination(selected, i);
	selected.pop_back(); //start인자를 갖는 경우를 벗어날 때, start 해당하는 값을 뺀다 
	return ;

}
int main(void) {
	string word;
	str = vector<string>(5);

	for (int i = 0; i < 5; i++) {
		cin >> str[i];

	}
	for (int i = 0; i < 5; i++) {

		combination(selected, i);//맨처음 선택한 값을 바꾼다.

	}
	for (int i = 0; i < retArray.size(); i++) {
		for (int j = 0; j < retArray[i].size(); j++){
			cout<<retArray[i][j]<<" ";
		}
		cout << "집합" << endl;
	}
	

}