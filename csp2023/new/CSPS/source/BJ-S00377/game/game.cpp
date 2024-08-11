#include<bits/stdc++.h>
using namespace std;
string s;
bool chk(string str){
    for(int i = 1; i < str.length(); i++){
        if(str[i-1] == str[i]) return false;
    }
    return true;
}
bool Moni(string str){
    while(!chk(str)){
        for(int i = 1; i < str.length(); i++){
            if(str[i-1] == str[i]){
                string s1, s2;
                for(int j = 0; j <= i - 2; j++) s1 += str[j];
                for(int j = i + 1; j <= str.length() - 1; j++) s2 += str[j];
                str = s1 + s2;
                break;
            }
        }
    }
    if(str.size() == 0){
        return true;
    }else return false;
}
bool check(int x, int y){
    string str;
    for(int i = x; i <= y; i++){
        str += s[i];
    }
    return Moni(str);
}
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int cnt = 0, n;
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        for(int j = i; j < s.length(); j++){
            if(check(i, j)) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
