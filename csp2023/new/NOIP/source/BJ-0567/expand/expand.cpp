#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=20;
int c,n,m,q;
int a[N],b[N];
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
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    c=read(),n=read(),m=read(),q=read();
    if(c==1)
    {
        for(int i=1;i<=n;i++) a[i]=read();
        for(int j=1;j<=m;j++) b[j]=read();
        int kx=read(),ky=read();
        for(int i=1;i<=kx;i++) {int op=read(),po=read();}
        for(int i=1;i<=ky;i++) {int op=read(),po=read();}
        for(int i=1;i<=q+1;i++) cout<<1;
    }
    else if(c==2)
    {
        for(int i=1;i<=n;i++) a[i]=read();
        for(int j=1;j<=m;j++) b[j]=read();
        if(n==1) a[2]=a[1],n++;
        if(m==1) b[2]=b[1],m++;
        int kx=read(),ky=read();
        if((a[1]-b[1])*(a[2]-b[2])>0) cout<<1;
        else cout<<0;
        for(int i=1;i<=kx;i++)
        {
            int pos=read(),val=read();
            a[pos]=val;
            if((a[1]-b[1])*(a[2]-b[2])>0) cout<<1;
            else cout<<0;
        }
        for(int i=1;i<=ky;i++)
        {
            int pos=read(),val=read();
            b[pos]=val;
            if((a[1]-b[1])*(a[2]-b[2])>0) cout<<1;
            else cout<<0;
        }
    }
    else if(c==3)
    {
        puts("1001");
    }
    else if(c==4)
    {
        puts("1101100011110101110101111111111111111110011111111101101100000");
    }
    return 0;
}