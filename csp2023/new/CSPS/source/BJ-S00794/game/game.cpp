#include <bits/stdc++.h>
using namespace std;
int n,ans,a[2000005];
string s;
stack<int> st,st2;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n >> s;
    for(int i = 0;i < n;i++){
        if(!st.empty() && s[i] == s[st.top()]){
            ans++;
            if(st.top() && a[st.top() - 1]) ans++;
            a[i] = a[st.top()] = 1;
            st.pop();
        }else st.push(i);
    }
    cout << ans;
    return 0;
}
