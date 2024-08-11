#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
int ans=0;
int ch[10];
void dfs(int now)
{
    if(now==6)
    {
        bool flag=1;
        for(int i=1; i<=n && flag; ++i)
        {
            int wz1=0,wz2=0;
            for(int j=1; j<=5; ++j)
            {
                if(ch[j]!=a[i][j])
                {
                    if(wz1==0) wz1=j;
                    else if(wz2==0) wz2=j;
                    else { flag=0; break; }
                }
            }
            if(wz1==0 || (wz2!=0 && wz2!=wz1+1)) { flag=0; break; }
            if(wz2==0) continue;
            else if((ch[wz1]-a[i][wz1]+10)%10!=(ch[wz2]-a[i][wz2]+10)%10) { flag=0; break; }
        }
        ans+=flag;
        return;
    }
    for(int i=0; i<=9; ++i) ch[now]=i,dfs(now+1);
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=5; ++j) cin>>a[i][j];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
