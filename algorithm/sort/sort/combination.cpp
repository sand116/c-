#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

//�κ����� ���ϱ� 

//1. �κ����� ������ �������� ���� ��� - ��� �κ������� ������ ���ϱ�

//for�� �ȿ� ��Ͱ� ����� ��� 
//for�� �ȿ� ��Ͱ� ������� ���� ��� 
using namespace std;
vector<vector<string>> retArray;
vector<string> str;
vector<string> selected;

void combination( vector<string> & selected, int start) {
	selected.push_back(str[start]);//start ���� �ְ�
	retArray.push_back(selected);
	// ������ ���յ� ���յ��� ã�Ƴ�����.
	for (int i = start+1; i < str.size(); i++) combination(selected, i);
	selected.pop_back(); //start���ڸ� ���� ��츦 ��� ��, start �ش��ϴ� ���� ���� 
	return ;

}
int main(void) {
	string word;
	str = vector<string>(5);

	for (int i = 0; i < 5; i++) {
		cin >> str[i];

	}
	for (int i = 0; i < 5; i++) {

		combination(selected, i);//��ó�� ������ ���� �ٲ۴�.

	}
	for (int i = 0; i < retArray.size(); i++) {
		for (int j = 0; j < retArray[i].size(); j++){
			cout<<retArray[i][j]<<" ";
		}
		cout << "����" << endl;
	}
	

}