#include <iostream>
#include <vector>
//deque, vector �������� unique, find���� ����, ���� algorithm find()/ unique() ��� �ؾ���
int main() {
	std::vector<int> vec(1);// ������ �Ҵ�ÿ� int�� �����ϸ�, �ڵ����� 0���� �Ҵ��Ѵ�!!!!!


	// ������ ���� ����ϱ�
	for (int i = vec.size() - 1; i >= 0; i--) {
		std::cout << vec[i] << std::endl;
	}
	//���� ��� for �� 
	for (auto& elem : vec)
		std::cout << "���� : " << elem << std::endl;
	
	//for�� �ۿ��� ���� �����ϱ�
	std::vector<int> a;
	for (int i = 0; i < 3; i++) {
	//�ʱ�ȭ�����ʴ� �⺻������ ȣ��
		a.push_back(i);
		std::cout<<a.size() << std::endl;
		
	}
	//for�� �ȿ��� ���� �����ϱ�
	for (int i = 0; i < 3; i++) {
		std::vector<int> b;//�ʱ�ȭ�����ʴ� �⺻������ ȣ�� - for���� ���Ƶ� ������ ��ü�� ���� 
		b.push_back(i);
		std::cout << b.size() << std::endl;
	}

	for (int i = 0; i < 3; i++) {
		std::vector<int> a = {i};// ���ο� �ʱ�ȭ ���� �� - �����ڿ� ���ο� ���� �����Ƿ� ���ο� ��ü�� �Ҵ�.
		std::cout  << a.size() << std::endl;

	}
	return 0;
}