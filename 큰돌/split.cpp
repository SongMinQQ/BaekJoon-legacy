#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos = 0;
    string token = "";
    //find 함수로 찾은 문자가 delimiter와 같을 때까지 반복
    //pos에는 찾은 문자열이 시작하는 index 반환
    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0,pos);
        ret.push_back(token);
        //erase함수로 0부터 찾은 문자열이 시작하는 index + 나누려는 문자열의 길이의 이전 index만큼 없앰
        input.erase(0,pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}