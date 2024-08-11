#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
void ok(int beg){
    stack<char> st;
    for(int i=beg;i<n;i++){
        if(!st.empty() && st.top()==s[i]) st.pop();
        else st.push(s[i]);
        if(st.empty()){
            ans++;
        }
    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>s;
    if(n<=10000){
        for(int i=0;i<n;i++){
            ok(i);
        }
        cout<<ans;
    }else{
        for(int i=0;i<n;i++){
            int u=1;
            if(s[i]==s[i+3] && s[i+1]==s[i+2]) ans++;
            while(s[i+u-1]==s[i+u]) u++;
            ans+=u*(u-1)/2; 
        }
        cout<<ans;
    }
    return 0;
}
