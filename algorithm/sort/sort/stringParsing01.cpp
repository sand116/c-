#include<iostream>
#include <string>
#include <sstream>
#include <vector>
// string <-> char ��ȯ
// string <-> int ��ȯ
using namespace std;
int main(void) {
	char s[] = "hello";
	string a = "aaa bbb ccc"; 
	string b = "aaa/bbb/ccc";
	stringstream ss;
	ss.str(a);
	string n;
	// 1. ssstream�̿��ؼ� ���� �Ľ��ϱ� 
	//���ڿ��� ������ 0 �� ��ȯ
	while (ss >> n) {
		cout << n << " ";
	}
	cout << endl;
	//cin>>n�̸� n�� ifstream���� �Է¹޴°�ó��, ss>>n�� string���� �Է¹޴´� cin�� ������ �н��ϵ��� ss�� �Ȱ��� ������ �н���

	//2. substr,find �̿��ؼ� �Ľ��ϱ� 
	int start = 0;
	int end = 0;
	vector<string> v;
	while(true) {
		end = b.find("/", start);
		//string size_t�� unsigned int
		//npos �� ���� -1, unsigned int �� ������ �����Ǹ� ���� ū ������ ���� ��
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