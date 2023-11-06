#include <iostream>
using namespace std;

//함수 2개를 중복해서 작성하는 경우
// int big(int a, int b ){
// 	int max = 100;
// 	int bigger = a > b ? a : b;
// 	if(bigger < max){
// 		return bigger;
// 	}
// 	else{
// 		return max;
// 	}
// }
// int big(int a, int b, int c){
// 	int bigger = a > b ? a : b;
// 	if(bigger < c){
// 		return bigger;
// 	}
// 	else{
// 		return c;
// 	}
// }

// 디폴트 매개변수 함수
int big(int a, int b, int c = 100){
	int bigger = a > b ? a : b;
	if(bigger < c){
		return bigger;
	}
	else{
		return c;
	}
}

int main(){
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
	return 0;
}