#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define _for1(i,a,b) for(int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=10;
int n,k[maxn][7];
int a[7],ans;
bool check(int a[])
{
    _for(i,1,n)
    {
        int ok=0;
        _for(j,1,5) if(a[j]!=k[i][j]) ok++;
        if(ok>=3||ok==0) return 0;
        else if(ok==1) continue;
        else
        {
            bool tr=0;
            _for(j,1,4)
                if(a[j]!=k[i][j]&&a[j+1]!=k[i][j+1]&&
                   (a[j]-k[i][j]+10==a[j+1]-k[i][j+1]||a[j+1]-k[i][j+1]+10==a[j]-k[i][j]||a[j]-k[i][j]==a[j+1]-k[i][j+1]))
                    tr=1;
            if(!tr) return 0;
        }
    }
    return 1;
}
void dfs(int i)
{
    if(i==6)
    {
        if(check(a))
            ans++;
        return;
    }
    _for(val,0,9)
    {
        a[i]=val;
        dfs(i+1);
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    _for(i,1,n)
        _for(j,1,5)
            cin>>k[i][j];
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
