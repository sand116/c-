#include <string>
#include <vector>
#include <iostream>
using namespace std;
int pairing(vector<int>&a, vector<int>&b, int rest, int start) {
	int ret=0;
	if (rest == 0) return ret=1;
	for (int idx = start; idx < a.size() - 1; idx=idx+2) {
		int f1 = a[idx];
		int f2 = a[idx + 1];
		if (b[f1] == 0 && b[f2] == 0) {
			b[f1] = b[f2] = 1;
			ret += pairing(a, b, rest - 2, idx + 2);
			b[f1] = b[f2] = 0;
		}
	}
	return ret;
}
void main() {
	int n = 4;
	int m = 6 ;
	int answer = 0;
	vector<int>a = { 0,1,1,2,2,3,3,0,0,2,1,3};
	vector<int>b(6, 0);
	answer = pairing(a,b,n,0);
	cout << answer;
	return;
}

