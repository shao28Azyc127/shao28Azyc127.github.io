#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char>st;
    int duan=0;
    int ans=0;
    char last;
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            if(last==s[i])ans++;
            duan++;
            st.push(s[i]);
        }
        else{
            char op=st.top();
            if(op!=s[i])st.push(s[i]);
            else{
                last=st.top();
                st.pop();
                ans++;
            }
        }
    }
    cout<<ans+(duan-1)*duan/2;
    return 0;
}
//aa aa bb aabb abba aaabba
