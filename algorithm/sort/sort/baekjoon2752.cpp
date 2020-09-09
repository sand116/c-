#include <stdio.h>;
#include <queue>;
#include <iostream>;
#include <algorithm>;
using namespace std;

int main(void) {
	int N;
	int num;
	vector<int> unsorted;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin.ignore();
		cin >> num;
		unsorted.push_back(num);
	}
	sort(unsorted.begin(),unsorted.end(),greater<int>());

	for (int i = 0; i < N; i++) {
		cout<< unsorted[i]<<endl;
	}
	return 0;
}