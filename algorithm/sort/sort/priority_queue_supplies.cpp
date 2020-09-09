#include <string>
#include <vector>
#include <iostream>
using namespace std;

void main() {
	int stock = 4;
	vector<int> dates = { 4,10,15 };
	vector<int> supplies = { 20,5,10 };
	int k = 30;
	int answer = 0;
	int rest = k - dates[0];
	int cnt = 0;
	vector<int>need;
	for (int i = 0; i < dates.size() - 1; i++) {
		need.push_back(dates[i + 1] - dates[i]);
	}
	need.push_back(k - dates.back());
	stock = stock - dates[0];

	while (stock < rest) {
		if (stock < need[cnt]) {
			stock = stock + supplies[cnt];
			cout <<"stock :"<< stock << endl;
			cout << "rest :" << rest << endl;
			answer++;
		}
		stock = stock - need[cnt];
		rest = rest - need[cnt];
		cnt++;

	}

	cout<<answer;
}