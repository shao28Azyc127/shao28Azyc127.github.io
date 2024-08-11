#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,cnt,ans,tot;
bool vis[1000000002];
void solve()
{
    tot++;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        if(flag%3==0)
        {
            if(i==n) ans=tot;
            vis[i]=true;
            flag++;
            cnt++;
            continue;
        }
        flag++;
    }
    if(cnt<n) solve();
    return;
}
 int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    solve();
    cout<<tot<<" "<<ans<<endl;
    return 0;
}





