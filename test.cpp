#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string sentence;

	cin >> sentence;

	string alphabet[7] = {"c=", "c-", "d-", "lj", " nj", "s=", "z="};
	string alphabet2 = "dz=";

	int count = 0;
	for(int i=0; i < sentence.size(); i++){
		for(int j = 0; j < 7; i++){
			sentence[i] + sentence[i+1] == alphabet[i]
			
		}
	}
	return 0;
}