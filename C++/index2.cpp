#include <iostream>
#include <string>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
    string name;
public:
    NamedCircle(int a = 0 , string b = "") : Circle(){
        this->name = b;
    };
    string getName() { return name; }
	void setName(string name) { this->name = name; }
};
int main(){
    cout << "5개의 정수 반지름과 원의 이름을 입력하세요" << endl;

    int setRadius;
    string setName;
    NamedCircle pizza[5];

    for(int i = 0; i < 5; i++) {
        cout << i+1 <<">> ";
        cin >> setRadius >> setName;
        pizza[i].setName(setName);
        pizza[i].setRadius(setRadius);
    }
    int max = 0, maxIndex;
    for(int i = 0; i < 5; i++){
        if (pizza[i].getArea() > max){
            max = pizza[i].getArea();
			maxIndex = i;
        }
    }
    cout << "가장 면적이 큰 피자는 " << pizza[maxIndex].getName() << "입니다" << endl;
}