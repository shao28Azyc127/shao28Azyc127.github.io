#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,n) for(int i=1;i<=n;i++)
LL n,now,flag,s;
LL z[1000005];
LL f(LL n,LL dep)
{
    if(n<=0) return dep;
    n=f(n-dep,dep+1);
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    s=f(n-1,1);
    cout << s << ' ';
    for(register int i=1;i<=n;i+=3)
    z[i]=1;
    for(register int i=2;i<=s;i++)
    {
        flag=0;
        for(register int j=1;j<=n;j++)
        {
            if(z[j]==0)
            {
                ++now;
                ++flag;
            }
            if(z[j]==0&&(now==3||flag==1))
            {
                z[j]=i;
                now=0;
            }
        }
    }
    cout << z[n];
    return 0;
}
