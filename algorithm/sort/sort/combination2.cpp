//2. �κ����� ������ ������ ��� - ����

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

//�κ����� ���ϱ� 


using namespace std;
vector<vector<string>> retArray;
vector<string> str;
vector<string> selected;

void combination(vector<string> & selected, int start) {
	selected.push_back(str[start]);//�� ó�� ���� ������ �̹� ����
	if (selected.size() == 3) {
		retArray.push_back(selected);
		selected.pop_back();//start�� �����ϱ�
		return;
	}
	// �� ó���� ������ ��  ������ ���յ� ���յ��� ã�Ƴ�����.
	for (int i = start + 1; i < str.size(); i++) combination(selected, i);
	selected.pop_back();//start�� �����ϱ�
	
	return;
}
int main(void) {
	string word;
	str = vector<string>(5); //5���߿� 3���� ���� ���

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
		cout << "����" << endl;
	}


}