#include <iostream>;
#include <string>;
#include <vector>;
#include <algorithm>;
using namespace std;
int main(void) {
	string word;
	vector<int> alpha(26,-1);
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		int idx = word[i] - 'a';
		if (alpha[idx] == -1) {
			alpha[idx] = i;
		}
	}

	for (int i = 0; i <alpha.size(); i++) {
		cout << alpha[i] << " ";
	}


	
}