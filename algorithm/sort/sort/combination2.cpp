//2. 부분집합 개수가 정해진 경우 - 조합

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

//부분집합 구하기 


using namespace std;
vector<vector<string>> retArray;
vector<string> str;
vector<string> selected;

void combination(vector<string> & selected, int start) {
	selected.push_back(str[start]);//맨 처음 값을 선택을 이미 했음
	if (selected.size() == 3) {
		retArray.push_back(selected);
		selected.pop_back();//start값 제외하기
		return;
	}
	// 맨 처음에 선택한 값  다음에 결합될 집합들을 찾아나선다.
	for (int i = start + 1; i < str.size(); i++) combination(selected, i);
	selected.pop_back();//start값 제외하기
	
	return;
}
int main(void) {
	string word;
	str = vector<string>(5); //5개중에 3개의 조합 출력

	for (int i = 0; i < 5; i++) {
		cin >> str[i];

	}
	for (int i = 0; i< 4; i++) {

		combination(selected, i);

	}
	for (int i = 0; i < retArray.size(); i++) {
		for (int j = 0; j < retArray[i].size(); j++) {
			cout << retArray[i][j] << " ";
		}
		cout << "집합" << endl;
	}


}