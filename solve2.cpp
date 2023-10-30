#include <iostream>

using namespace std;

class MyIntStack{
    int *p;
    int size;
    int tos = 0;
public:
    MyIntStack();
    MyIntStack(int size);
    MyIntStack(const MyIntStack& s);
    ~MyIntStack();
    bool push(int n);
    bool pop(int &n);
};

MyIntStack::MyIntStack(int size) : size(size){
    p = new int[size];
    tos = 0;
}
MyIntStack::~MyIntStack() {
    delete[] p;
}

MyIntStack::MyIntStack(const MyIntStack& s) {
    size = s.size;
    tos = s.tos;
    p = new int[size];
    for (int i = 0; i < size; i++) {
        p[i] = s.p[i];
    }
}

bool MyIntStack::push(int n){
    if(tos == size){
        return false;
    }
    else{
        p[tos] = n;
        tos++;
        return true;}
}
bool MyIntStack::pop(int &n){
    if(tos < 0){
        return false;
    }
    else{
        n = p[tos - 1];
        if(tos != 0){
            tos--;
        }
        return true;
    }
}

int main(){
    MyIntStack a(10);
    a.push(10);
    a.push(20);
    MyIntStack b = a;
    b.push(30);

    int n;
    a.pop(n);
    cout << "스택 a에서 팝한 값 " << n << endl;
    b.pop(n);
    cout << "스택 b에서 팝한 값 " << n << endl;
    return 0;
}