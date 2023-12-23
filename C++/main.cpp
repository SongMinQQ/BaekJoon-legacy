#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("C:\\Windows\\system.ini", ios::in | ios::binary);
    ofstream fout("C:\\Temp\\system.txt", ios::out | ios::binary);
    if(!fin || !fout){
        cout << "파일없음" << endl;
    }

    fin.seekg(0, ios::end);
	int location = fin.tellg();
	int a;
	for (int i = 0; i < location; i++) {
		fin.seekg(location - i - 1, ios::beg);
		a = fin.get();
		fout.put(a);
	}
    return 0;
}