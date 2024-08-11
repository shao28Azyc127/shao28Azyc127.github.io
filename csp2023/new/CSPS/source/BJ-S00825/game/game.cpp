#include<bits/stdc++.h>
using namespace std;
#define int long long
stack<char>s;
int n;
char c[2000005];
int ans=0;
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>c+1;
    for(int i=1;i<=n;i++){
        while(!s.empty())s.pop();
        for(int j=i;j<=n;j++){
            if(!s.empty()&&s.top()==c[j])s.pop();
            else s.push(c[j]);
            if(s.empty())ans++;
        }
    }
    cout<<ans;
}
