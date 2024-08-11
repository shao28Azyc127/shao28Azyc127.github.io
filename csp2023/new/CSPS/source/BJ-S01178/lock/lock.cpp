#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=10;

int n,ans,a[15][8],t[8];

bool check2(int a1,int a2,int x,int y,int z,int i)
{
    if((a[i][a1]+t[a2])%10!=(a[i][a2]+t[a1])%10)
        return 0;
    if(a[i][a1]==t[a1])
        return 0;
    if(a[i][x]!=t[x])
        return 0;
    if(a[i][y]!=t[y])
        return 0;
    if(a[i][z]!=t[z])
        return 0;
    return 1;
}

void check(int x)
{
    for(int i=1;i<=5;i++)
    {
        t[5-i+1]=x%10;
        x/=10;
    }
    int f=1,dif;
    for(int k=1;k<=n;k++)
    {
        dif=0;
        for(int i=1;i<=5;i++)
        {
            if(t[i]!=a[k][i])
                dif++;
        }
        if(dif==1)
            continue;
        bool F=0;
        if(check2(1,2,3,4,5,k))
            F=1;
        if(check2(2,3,1,4,5,k))
            F=1;
        if(check2(3,4,1,2,5,k))
            F=1;
        if(check2(4,5,1,2,3,k))
            F=1;
        if(F)
            continue;
        f=0;
        break;
    }
    if(f)
    {
        ans++;
    }
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>a[i][j];
    if(n==1)
    {
        cout<<81<<endl;
    }
    else
    {
        for(int i=0;i<=99999;i++)
            check(i);
        cout<<ans<<endl;
    }
    return 0;
}

