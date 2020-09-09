#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> s;
int cnt = 0;
void dfs(vector<int>&numbers, int start, int sum, string op) {
	cnt++;
	if (start == numbers.size()) {
		
		s.push_back(sum);
		
		return;
	}
	if (op.compare("+") == 0) {
		sum += numbers[start];
	}
	if (op.compare("-") == 0) {
		sum -= numbers[start];
	}
	dfs(numbers, start+1, sum, "+");
	dfs(numbers, start+1, sum, "-");
	
	return;
}
void main() {
	vector<int> numbers = { 1, 1, 1, 1, 1 };
	int target = 3;
	int answer = 0;
	int cnt = 0;
	dfs(numbers, 0, 0, "+");
	dfs(numbers, 0, 0, "-");
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 3) {
			answer++;
		}
	}
	cout << answer/2;
}