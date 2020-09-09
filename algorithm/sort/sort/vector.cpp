#include <iostream>
#include <vector>
//deque, vector 내장으로 unique, find지원 안함, 따라서 algorithm find()/ unique() 사용 해야함
int main() {
	std::vector<int> vec(1);// 사이즈 할당시에 int로 설정하면, 자동으로 0값을 할당한다!!!!!


	// 끝에서 부터 출력하기
	for (int i = vec.size() - 1; i >= 0; i--) {
		std::cout << vec[i] << std::endl;
	}
	//범위 기반 for 문 
	for (auto& elem : vec)
		std::cout << "원소 : " << elem << std::endl;
	
	//for문 밖에서 벡터 생성하기
	std::vector<int> a;
	for (int i = 0; i < 3; i++) {
	//초기화되지않는 기본생성자 호출
		a.push_back(i);
		std::cout<<a.size() << std::endl;
		
	}
	//for문 안에서 벡터 생성하기
	for (int i = 0; i < 3; i++) {
		std::vector<int> b;//초기화되지않는 기본생성자 호출 - for문을 돌아도 이전의 객체와 동일 
		b.push_back(i);
		std::cout << b.size() << std::endl;
	}

	for (int i = 0; i < 3; i++) {
		std::vector<int> a = {i};// 새로운 초기화 값이 들어감 - 생성자에 새로운 값이 들어갔으므로 새로운 객체를 할당.
		std::cout  << a.size() << std::endl;

	}
	return 0;
}