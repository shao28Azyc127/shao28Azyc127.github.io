#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return b==0? a: gcd(b,a%b);
}
int T,M;
int a,b,c;
int r;
int p1,q1,p2,q2,p3,q3,g1,g2,g3;
void solve()
{
    p1=q1=p2=q2=p3=q3=g1=g2=g3=0;
    p1=-b;
    q1=2*a;
    if(q1<0)
    {
        p1=~p1+1;
        q1=~q1+1;
    }
    g1=abs(gcd(abs(p1),abs(q1)));
    p1/=g1;
    q1/=g1;
    if(r<0)
    {
        printf("NO\n");
        return;
    }
    if(r==0)
    {
        if(p1<0)
        {
            putchar('-');
            p1=~p1+1;
        }
        printf("%d",p1);
        if(q1!=1&&p1!=0)printf("/%d",q1);
        putchar('\n');
        return;
    }
    p2=1;
    for(int i=2;i*i<=r;i++)
    {
        while((r%(i*i))==0)
        {
            r/=(i*i);
            p2*=i;
        }
    }
    q2=abs(2*a);
    if(q2<0)
    {
        q2=~q2+1;
    }
    g2=abs(gcd(p2,q2));
    p2/=g2;
    q2/=g2;

        if(r==1)
        {
            int g=abs(gcd(q1,q2));
            p1=p1*q2/g+p2*q1/g;
            q1=q1*q2/g;
            g=abs(gcd(p1,q1));
            p1/=g;
            q1/=g;
            if(p1<0)
            {
                putchar('-');
                p1=~p1+1;
            }
            printf("%d",p1);
            if(q1!=1&&p1!=0)printf("/%d",q1);
            putchar('\n');
        }
        else
        {
            if(p1!=0)printf("%d",p1);
            if(q1!=1&&p1!=0)printf("/%d",q1);
            if(p2>0&&p1!=0)putchar('+');
            if(p2<0)
            {
                putchar('-');
                p2=~p2+1;
            }
            if(p2!=1)printf("%d*",p2);
            printf("sqrt(%d)",r);
            if(q2!=1&&p2!=0)printf("/%d",q2);
            putchar('\n');
        }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d %d",&T,&M);
    while(T--)
    {
        scanf("%d %d %d",&a,&b,&c);
        r=b*b-4*a*c;
        solve();
    }
    return 0;
}
