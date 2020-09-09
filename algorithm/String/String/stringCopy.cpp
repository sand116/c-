#include <iostream>
#include <string>
using namespace std;
void main() {
	/*
	string.copy(string 값을 복사할 char[]배열,len길이,시작index) 
	
	*/
	char a[10];
	string b = "mask";
	int len = b.copy(a, b.length(), 0); //a 길이 반환 
	a[len] = '\0';

}