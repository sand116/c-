#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;
bool compare(vector<int>&a, vector<int>&b) {
	if (a[0] == b[0]) return a[1] > b[1];
	else return a[0] > b[0];
}
bool compare2(vector<int>&a, vector<int>&b) {
	return a[1] > b[1];
}
void main() {
	vector<vector<int>> jobs = { {0, 3 }, { 1, 9 }, { 2, 6 } };
	int answer = 0;
	int time = 0;
	int t = 0;
	int sum = 0;
	int size = jobs.size();
	make_heap(jobs.begin(), jobs.end(), compare);
	t = jobs.front()[1] - jobs.front()[0];
	sum = jobs.front()[1];
	pop_heap(jobs.begin(), jobs.end(), compare);
	jobs.pop_back();
	while(!jobs.empty()) {

		
		time += t;
		cout << "t " <<t << endl;
		cout << "sum "<< sum << endl;
		
		for (int i = 0; i < jobs.size(); i++) {
			if (jobs[i][0] < time) jobs[i][1] += time - jobs[i][0];
			cout << "round" <<jobs[i][1] << " ";
		}
		make_heap(jobs.begin(), jobs.end(), compare2);
		t = jobs.front()[1] - (time - jobs.front()[0]);
		sum += jobs.front()[1];
		pop_heap(jobs.begin(), jobs.end(),compare2);
		jobs.pop_back();

	

	}
	cout<< sum/size;
}