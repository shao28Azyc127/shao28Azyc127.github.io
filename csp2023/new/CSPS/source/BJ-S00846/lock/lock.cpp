//100
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
int n;
int a[10][10];
int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
void Task2()
{
    int pswd;
    int ans=0;
    int p[10];
    for(pswd=0;pswd<=99999;pswd++)
    {
        p[1]=pswd/10000;
        p[2]=(pswd%10000)/1000;
        p[3]=(pswd%1000)/100;
        p[4]=(pswd%100)/10;
        p[5]=pswd%10;
        int lstdiff=-1,diffnum=0;
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            lstdiff=-1,diffnum=0;
            for(int j=1;j<=5;j++)
            {
                if(p[j]!=a[i][j])
                {
                    if(lstdiff==-1) lstdiff=j,diffnum=1;
                    else if(j-lstdiff>1 || diffnum==1)
                    {
                        flag=1;
                        break;
                    }
                    else diffnum++;
                }
            }
            if(flag) break; 
        }
        if(!flag)
        {
            // cout<<pswd<<endl;
            ans++;
        }
    }
    printf("%d\n",ans);
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=5;j++)
            a[i][j]=read();
    // if(n==1) Task1();
    Task2();
    return 0;
}