#include <iostream>
#include <string>

using namespace std;

int main() {
	string sentence;

	cin >> sentence;

	string alphabet[7] = { "c=", "c-", "d-", "lj", "nj", "s=", "z=" };
	string alphabet2 = "dz=";

	int count = 0;
	
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < sentence.size() - 1; i++) {
			if (sentence[i] == alphabet[j][0] && sentence[i + 1] == alphabet[j][1]) {
				count++;
			}
		}
	}
	for (int i = 0; i < sentence.size() - 2; i++) {
		if (sentence[i] == alphabet2[0] && sentence[i + 1] == alphabet2[1] && sentence[i + 2] == alphabet2[2]) {
			count++;
		}
	}

	cout << sentence.length() - count;
	
	return 0;
}
