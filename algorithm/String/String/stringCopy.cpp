#include <iostream>
#include <string>
using namespace std;
void main() {
	/*
	string.copy(string ���� ������ char[]�迭,len����,����index) 
	
	*/
	char a[10];
	string b = "mask";
	int len = b.copy(a, b.length(), 0); //a ���� ��ȯ 
	a[len] = '\0';

}