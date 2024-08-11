#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int base[5]={1,10,100,1000,10000};

int n,x,a,ans;
int cnt[100005];

inline int icr(int y,int p,int v)
{
    int res=y/v%10;
    return y-res*v+((res+p)%10)*v;
}

inline void add()
{
    for(int i=0;i<5;i++)
    {
        for(int j=1;j<10;j++)
            cnt[icr(x,j,base[i])]++;
    }

    for(int i=0;i<4;i++)
    {
        for(int j=1;j<10;j++)
            cnt[icr(icr(x,j,base[i]),j,base[i+1])]++;
    }
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        x=0;
        for(int j=0;j<5;j++)
        {
            cin>>a;
            x=x*10+a;
        }

        add();
    }

    for(int i=0;i<100000;i++)
    {
        if(cnt[i]==n)
            ans++;
    }

    cout<<ans<<'\n';

    return 0;
}
