#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
int n;
string s;
int ans;
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;
    bool flag = true;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            flag = false;
            break;
        }
    }
    if(flag){
        cout <<0 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        stack<char> a;
        for(int j = i; j < n; j++){
            if(!a.empty() && a.top() == s[j]){
                a.pop();
            }else{
                a.push(s[j]);
            }
            if(a.empty()){
                ans++;
            }
        }
    }
    cout <<ans <<endl;
    return 0;
}

