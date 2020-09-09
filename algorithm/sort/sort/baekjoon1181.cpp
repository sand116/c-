#include<iostream>;
#include<vector>;
#include<string>;
#include<algorithm>;


using namespace std;
int N;
string word;
vector<string> unsorted;

//참조형으로 오름차순 greator<int>() less<int>()
bool compare(const string &a, const string &b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();	//오름차순으로 정렬

}
int main(void) {
	cin >> N ;
	unsorted = vector<string>(N);
	for (int i = 0; i < N; i++) {
		cin >> word;
		unsorted.push_back(word);
	}
	sort(unsorted.begin(), unsorted.end(),compare);

	unsorted.erase(unique(unsorted.begin(), unsorted.end()),unsorted.end());
	for (int i = 0; i<unsorted.size();i++) {
		cout << unsorted[i]<<endl;
	}
	return 0;
}