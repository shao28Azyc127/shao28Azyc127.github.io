#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans,n;
string s;
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;getchar();
    getline(cin,s);
    for(int i=1;i<=n;i++){
        stack<int> sta;
        for(int j=i;j<=n;j++){
            int now=s[j-1]-'a';
            if(sta.size()&&sta.top()==now) sta.pop();
            else sta.push(now);
            if(sta.empty()){
                ans++;
            }
        }
    }cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
}