#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>

#pragma warning( disable : 4996; once : 4385; error : 164 )
using namespace std;

int main(void) {
	string s;
	int cnt = 0;
	getline(cin,s);
	string::size_type first = s.find_first_not_of(" ");
	string::size_type last = s.find_last
		_not_of(" ");
	for (int i = first; i < last+1; i++) {
		if (s[i] == ' ') {
			cnt++;
		}
	}
	cout << cnt + 1;
	
}
/*
string s;
	char s2[1000000];
	vector<string>q;
	getline(cin,s);
	strcpy(s2, s.c_str());
	char *tok;
	tok = strtok(s2, " ");
	while (tok != nullptr){
		q.push_back(string(tok));
		tok = strtok(nullptr, " ");//null을 넣으면 위에 내부 버퍼에서 종료지점부터 디사 ""앞의 문자열을 반환
	}
	for (int i = 0; i < q.size(); i++) {
		cout << q[i] << endl;	}


*/