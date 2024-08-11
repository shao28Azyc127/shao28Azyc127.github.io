#include<bits/stdc++.h>
#define debug printf("Im3tsmh\n")
using namespace std;
const int inf=0x3f3f3f3f;
int n,c[1000005];
int a0,b0,c0,d0,e0;
int a1,b1,c1,d1,e1,num;
int ans;
void change1()
{
    for(int i=1;i<=9;++i)
    {
        a1=(a0+i)%10;
        num=a1*10000+b1*1000+c1*100+d1*10+e1;
        ++c[num];
    }
    a1=a0;
    for(int i=1;i<=9;++i)
    {
        b1=(b0+i)%10;
        num=a1*10000+b1*1000+c1*100+d1*10+e1;
        ++c[num];
    }
    b1=b0;
    for(int i=1;i<=9;++i)
    {
        c1=(c0+i)%10;
        num=a1*10000+b1*1000+c1*100+d1*10+e1;
        ++c[num];
    }
    c1=c0;
    for(int i=1;i<=9;++i)
    {
        d1=(d0+i)%10;
        num=a1*10000+b1*1000+c1*100+d1*10+e1;
        ++c[num];
    }
    d1=d0;
    for(int i=1;i<=9;++i)
    {
        e1=(e0+i)%10;
        num=a1*10000+b1*1000+c1*100+d1*10+e1;
        ++c[num];
    }
    e1=e0;
}
void change2()
{
    for(int i=1;i<=9;++i)
    {
        a1=(a0+i)%10;
        b1=(b0+i)%10;
        num=a1*10000+b1*1000+c1*100+d1*10+e1;
        ++c[num];
    }
    a1=a0;b1=b0;
    for(int i=1;i<=9;++i)
    {
        b1=(b0+i)%10;
        c1=(c0+i)%10;
        num=a1*10000+b1*1000+c1*100+d1*10+e1;
        ++c[num];
    }
    b1=b0;c1=c0;
    for(int i=1;i<=9;++i)
    {
        c1=(c0+i)%10;
        d1=(d0+i)%10;
        num=a1*10000+b1*1000+c1*100+d1*10+e1;
        ++c[num];
    }
    c1=c0;d1=d0;
    for(int i=1;i<=9;++i)
    {
        d1=(d0+i)%10;
        e1=(e0+i)%10;
        num=a1*10000+b1*1000+c1*100+d1*10+e1;
        ++c[num];
    }
    d1=d0;e1=e0;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d%d%d",&a1,&b1,&c1,&d1,&e1);
        a0=a1;b0=b1;c0=c1;d0=d1;e0=e1;
        num=a1*10000+b1*1000+c1*100+d1*10+e1;
        c[num]=-inf;
        change1();
        change2();
    }
    for(int i=0;i<=99999;++i)
    {
        if(c[i]==n)
        {
            ++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}

