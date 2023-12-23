#include <iostream>

using namespace std;

int main() {
    int num;
    int matrix[101][101];
    fill(&matrix[0][0],&matrix[100][101],0);
    cin >> num;

    int a, b;
    for(int i = 0; i < num; i++){
        cin >> a >> b;
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                matrix[a+j][b+k] = matrix[a+j][b+k] + 1;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(matrix[i][j] >= 1){
                count++;
            }
        }
    }
    cout << count ;
    return 0;
}