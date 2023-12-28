#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> m;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    string select2;

    cin >> a >> b;
    for(int i = 0; i < a; i++){
        string numStr = to_string(i + 1);
        cin >> select2;
        m[numStr] = select2;
        m[select2] = numStr;
    }

    for(int i = 0; i < b; i++){
        cin >> select2;
        cout << m[select2] << '\n';
    }
    return 0;
}
