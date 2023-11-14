#include <iostream>

using namespace std;

class Matrix;
void operator >>(Matrix mat1, int mat2[4]);
Matrix& operator <<(Matrix& mat1, int mat2[4]);

class Matrix {
int arr[4];
public:
    Matrix() : Matrix(0, 0, 0, 0) {};
    Matrix(int m1, int m2, int m3, int m4) {
		arr[0] = m1;
		arr[1] = m2;
		arr[2] = m3;
		arr[3] = m4;
	}
    void show() {
        cout << "Matrix = { ";
        for(int i = 0; i < 4; i++){
            cout << arr[i] << ' ';
        }
        cout <<'}';
    }
    friend void operator >>(Matrix mat1, int mat2[4]);
	friend Matrix& operator <<(Matrix& mat1, int mat2[4]);
};

void operator >>(Matrix mat1, int mat2[4]) {
	for (int i = 0; i < 4; i++)
		mat2[i] = mat1.arr[i];
}
Matrix& operator <<(Matrix &mat1,int mat2[4]) {
	for (int i = 0; i < 4; i++)
		mat1.arr[i] = mat2[i];
	return mat1;
}

int main(){
    Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << endl;
	b.show();

	return 0;

}