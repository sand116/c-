#include <iostream>;
#include <string>;
#include <vector>;
#include <algorithm>;
using namespace std;
int main(void) {
	int T;
	int R;
	string S;
	string P;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> R >> S;
		for (int j = 0; j < S.size(); j++) {
			for (int r = 0; r < R; r++) {
				P.push_back(S[j]);
			}

		}
		cout<< P<<endl;
		P.clear();
	}
	


	return 0;

}