#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    int count = 0;
    ifstream fin("C:\\Windows\\system.ini", ios::in);
    ofstream fout("C:\\Temp\\system.txt", ios::out | ios::binary);
    if(!fin||!fout){
        cout << "파일없음" << endl;
    }

    int a;
    while((a=fin.get())!=EOF){
        if(isupper(a)){
            a = tolower(a);
        }
        else if(islower(a)){
            a = toupper(a);
        }
    if(a == ' ' || a == '\n'){
        count++;
    }

        fout.put((char)a);

    }
    cout<< "file words number : " << count << endl;
    fin.close();

    
    return 0;
}