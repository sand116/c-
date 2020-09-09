#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
string s;
vector<int> q(26, 0);

int main(void){
	int max=0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		q[toupper(s[i]) - 65] += 1;
	
	}
	for (int i = 1; i < q.size(); i++) {
		if (q[max] <q[i]) {
			max = i;
		}
	}
	for (int i = 1; i < q.size(); i++) {
		if (max != i) {
			if (q[i] == q[max]) {
				cout << "?" << endl;
				return 0;
			}
		}
	}
	cout << char(max+65) << endl;
	return 0;
}