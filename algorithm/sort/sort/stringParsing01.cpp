#include<iostream>
#include <string>
#include <sstream>
#include <vector>
// string <-> char 변환
// string <-> int 변환
using namespace std;
int main(void) {
	char s[] = "hello";
	string a = "aaa bbb ccc"; 
	string b = "aaa/bbb/ccc";
	stringstream ss;
	ss.str(a);
	string n;
	// 1. ssstream이용해서 공백 파싱하기 
	//문자열이 끝나면 0 을 반환
	while (ss >> n) {
		cout << n << " ";
	}
	cout << endl;
	//cin>>n이면 n을 ifstream에서 입력받는것처럼, ss>>n은 string에서 입력받는다 cin이 공백을 패스하듯이 ss도 똑같이 공백을 패스함

	//2. substr,find 이용해서 파싱하기 
	int start = 0;
	int end = 0;
	vector<string> v;
	while(true) {
		end = b.find("/", start);
		//string size_t는 unsigned int
		//npos 는 음수 -1, unsigned int 가 음수로 설정되면 가장 큰 값으로 세팅 됨
		if (end == string::npos) {
			v.push_back(b.substr(start));
			break;
		}
		v.push_back(b.substr(start,end-start));
		start = end + 1;
	}
	//
	return 0;
}