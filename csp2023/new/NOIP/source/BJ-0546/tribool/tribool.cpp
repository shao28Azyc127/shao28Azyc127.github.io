#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int MAX=1e5+5;

/*

123

1-13

1-11

1-11
U=1
T=2
F=3

123
1-13
1-11
-111



*/

int n,m;
int c,t;
int cnt[MAX];
int flag[MAX];

void ch(int num)
{
    if(num<0)
    {
        num=-num;
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==num&&flag[i]==0)
        {
            flag[i]=flag[num];
            ch(i);
        }
        if(cnt[i]==-num&&flag[i]==0)
        {
            flag[i]=5-flag[num];
            if(flag[i]==4)
            {
                flag[i]=1;
            }
            ch(i);
        }

    }
    return;
}


int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cnt[i]=i;
            flag[i]=0;
        }
        while(m--)
        {
            char k;
            cin>>k;
            if(k=='T')
            {
                int a;
                cin>>a;
                flag[a]=2;
                cnt[a]=a;
            }
            if(k=='F')
            {
                int a;
                cin>>a;
                flag[a]=3;
                cnt[a]=a;
            }
            if(k=='U')
            {
                int a;
                cin>>a;
                flag[a]=1;
                cnt[a]=a;
            }
            if(k=='+')
            {
                int a,b;
                cin>>a>>b;
                cnt[a]=cnt[b];
                flag[a]=0;
            }
            if(k=='-')
            {
                int a,b;
                cin>>a>>b;
                cnt[a]=-cnt[b];
                flag[a]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]==-i)
            {
                flag[i]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(flag[i]!=0)
            {
                ch(i);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(flag[i]==1)
            {
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

