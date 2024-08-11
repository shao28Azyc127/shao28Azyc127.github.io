#include<bits/stdc++.h>
using namespace std;

string s;
long n,ans;
bool dd(string x){
    stack<char>num;
    for(register int i = 0;i < x.size();i++){
        if(num.empty()){
            num.push(x[i]);
        }
        else{
            if(x[i] == num.top()){
                num.pop();
            }
            else{
                num.push(x[i]);
            }
        }
    }
    return num.empty();
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> s;
    s = " " + s;
    for(register int i = 1;i <= n;i++){
        for(int j = i+1;j <= n;j += 2){
            string b = "";
            for(register int k = i;k <= j;k++){
                b += s[k];
            }
            if(dd(b)){
                ans++;
            }
        }
    }
    cout << ans;
}
