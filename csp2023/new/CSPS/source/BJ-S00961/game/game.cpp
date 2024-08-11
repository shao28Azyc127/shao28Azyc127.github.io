#include<bits/stdc++.h>
using namespace std;
stack<char> s;
string str;
int main(){
    int ans = 0;
    int n;
    freopen("game.in", "r", stdin);
    freopen("game.ans", "w", stdout);
    scanf("%d", &n);
    cin >> str;
    
    for(int i = 0; i < n; i ++){
        char x = str[i];
        if(!s.empty() && x == s.top()){
            s.pop();
            ans ++;
            // cout << i << endl;
        }
        else{
            s.push(x);
        }
    }
    if(s.empty()) ans ++;
    printf("%d", ans);
    return 0;
}