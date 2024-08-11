#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool ok[100002],res[100002];
int cp(int a,int b,int c,int d,int e)
{
    return a*10000+b*1000+c*100+d*10+e;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    memset(res,1,sizeof(res));
    while(n--)
    {
        memset(ok,0,sizeof(ok));
        int a[5];
        for(int i=0;i<5;i++)
            cin>>a[i];
        for(int i=0;i<5;i++)
        {
            for(int j=1;j<10;j++)
            {
                a[i]=(a[i]+1)%10;
                ok[cp(a[0],a[1],a[2],a[3],a[4])]=1;
            }
            a[i]=(a[i]+1)%10;
        }
        for(int i=1;i<5;i++)
        {
            for(int j=1;j<10;j++)
            {
                a[i-1]=(a[i-1]+1)%10;
                a[i]=(a[i]+1)%10;
                ok[cp(a[0],a[1],a[2],a[3],a[4])]=1;
            }
            a[i-1]=(a[i-1]+1)%10;
            a[i]=(a[i]+1)%10;
        }
        for(int i=0;i<100000;i++)
            res[i]&=ok[i];
    }    
    int ans=0;
    for(int i=0;i<100000;i++)
        ans+=res[i];
    cout<<ans;
    return 0;
}