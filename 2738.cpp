#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int** arr = new int*[a];
	int** arr2 = new int*[b];

	for (int i = 0; i < a; i++) {
		arr[i] = new int[b];
		for (int j = 0; j < b; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < a; i++) {
		arr2[i] = new int[b];
		for (int j = 0; j < b; j++) {
			cin >> arr2[i][j];
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << arr[i][j] + arr2[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
