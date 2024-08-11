#include <bits/stdc++.h>
#define ST 100000
#define N 10
using namespace std;
int n;
int a[N][10];
int b[ST+10];
int mx,ans;
int tmp[10];
inline int to_st()
{
    return tmp[1]*10000+tmp[2]*1000+tmp[3]*100+tmp[4]*10+tmp[5];
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
            cin>>a[i][j];
    }
    int st;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=9;j++)
        {
            for(int k=1;k<=5;k++)tmp[k]=a[i][k];
            for(int k=1;k<=5;k++)
            {
                tmp[k-1]=a[i][k-1];
                tmp[k]+=j;
                tmp[k]%=10;
                st=to_st();
                b[st]++;
                mx=max(mx,b[st]);
            }
            for(int k=1;k<=5;k++)tmp[k]=a[i][k];
            for(int k=1;k<5;k++)
            {
                tmp[k-1]=a[i][k-1];tmp[k]=a[i][k];
                tmp[k]+=j;
                tmp[k]%=10;
                tmp[k+1]+=j;
                tmp[k+1]%=10;
                st=to_st();
                b[st]++;
                mx=max(mx,b[st]);
            }
        }
    }
    for(int i=1;i<=ST;i++)
    {
        ans+=(b[i]==mx?1:0);
    }
    cout<<ans;
    return 0;
}
