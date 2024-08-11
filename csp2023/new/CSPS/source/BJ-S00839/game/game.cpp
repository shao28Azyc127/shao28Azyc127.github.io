#include<bits/stdc++.h>
using namespace std;

int n;
string str;

bool check(string s){
    stack<char> st;
    st.push(s[0]);
    for(int i=1;i<s.length();i++){
        if(st.empty() || st.top() != s[i]){
            st.push(s[i]);
        }else{
            st.pop();
        }
    }
    if(st.size() != 0) return false;
    return true;
}

set<string> s;
int cnt = 0;
int main(){

    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> str;
    if(n == 1){
        cout << 0;
        return 0;
    }
    if(n == 2){
        if(str[0] == str[1]) cout << 1;
        else cout << 0;
        return 0;
    }
    for(int i=2;i<=n;i++){
        for(int j = 0;j < n-i+1;j++){
            if(check(str.substr(j, i))){
                cnt++;
            }
        }
    }
    cout << cnt;


    return 0;
}
