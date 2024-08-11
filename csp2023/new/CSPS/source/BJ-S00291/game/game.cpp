#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
int main(){
    #ifndef JZQ
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin>>n>>s;
    s=" "+s+" ";
    ll ans=0;
    for(int i=1;i<=n;i++){
        stack<char> lst;
        lst.push(s[i]);
        for(int j=i+1;j<=n;j++){
            if(lst.empty()||s[j]!=lst.top()) lst.push(s[j]);
            else lst.pop();
            if(lst.empty()) ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}