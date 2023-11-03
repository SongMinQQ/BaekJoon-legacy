#include <iostream>
#include <string>

using namespace std;

void numReset(int (&a)[26]){
	for(int i = 0; i < 26; i++){
		a[i] = 0;
	}
}

int main() {
	int strnum, indexnum = 0, beforeindexnum = 0,breaking = 0, count = 0;

	cin >> strnum;

	string *sentence = new string[strnum];

	for(int i = 0; i < strnum; i++){
		cin >> sentence[i];
	}

	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int num[26];

	numReset(num);

	for(int i = 0; i < strnum; i++){
		for(int k = 0; k < 26; k++){
			if(sentence[i][0] == alphabet[k]){
					num[k] = num[k] + 1;
			}
		}
		for(int j = 1; j < sentence[i].length(); j++){
			for(int k = 0; k < 26; k++){
				if(sentence[i][j] == alphabet[k]){
					indexnum = k;
					break;
				}
			}
			for(int k = 0; k < 26; k++){
				if(sentence[i][j] != sentence[i][j-1]  && num[indexnum] != 0 && num[beforeindexnum] > 0){
					breaking++;
					break;
				}
				if(sentence[i][j] == alphabet[k]){
					num[k] = num[k] + 1;
					beforeindexnum = k;
					break;
				}
				
			}
		}
		if(breaking == 0){
			count++;
		}
		breaking = 0;
		numReset(num);
	}

	cout << count;
	return 0;
}
