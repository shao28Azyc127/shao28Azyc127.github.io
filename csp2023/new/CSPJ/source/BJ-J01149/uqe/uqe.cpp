#include <bits/stdc++.h>
using namespace std;
int wai,nei;
int const N=3e3+1;
int base[N];
inline void Init()
{
    for(int i=1;i<N;i++)
        base[i]=i*i;
}
inline bool is_zheng(double x)
{
    return ceil(x)==floor(x);
}
inline int gcd(int a,int b)
{
    while(b)
    {
        int t=a;
        a=b;
        b=t%b;
    }
    return a;
}
inline void get_frac(int a,int b,int type)
{
    if(a==0)
    {
        if(type==1) return ;
        printf("0");
    }
    int flag;
    if((a<0 && b<0) || (a>0 && b>0)) flag=1;
    else flag=-1;
    a=abs(a),b=abs(b);
    int d=gcd(a,b);
    a/=d,b/=d;
    a=a*flag;
    if(type!=2)
    {
        if(b!=1) printf("%d/%d",a,b);
        else printf("%d",a);
        if(type==1) printf("+");
    }
    if(type==2)
    {
        if(a==1)
            printf("sqrt(%d)/%d",nei,b);
        else printf("%d*sqrt(%d)/%d",a,nei,b);
    }
}
int Solve(int x)
{
    int ans=1,i=int(sqrt(x))+1;
    while(x && i>=1)
    {
        if(x%base[i]==0)
        {
            x/=base[i];
            ans*=i;
        }
        i--;
    }
    return ans;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c,T,M,derta;
    double zheng,t,xiao,gen,tmp;
    scanf("%d%d",&T,&M);
    Init();
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&c);
        //cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
        derta=(b*b)-(4*a*c);
        if(derta<0)
        {
            printf("NO\n");
            continue;
        }
        else if(derta==0)
        {
            zheng=-0.5*(double)b/a;
            if(is_zheng(zheng))
            {
                printf("%d\n",int(zheng));
                continue;
            }
            else get_frac(-b,2*a,0);
            printf("\n");
            continue;
        }
        t=sqrt(derta);
        double x=(-b+t)/(double)(2*a);
        double y=(-b-t)/(double)(2*a);
        if(x<y) t=-t;
        tmp=max(x,y);
        if(is_zheng(tmp))
        {
            printf("%d\n",int(tmp));
            continue;
        }
        else
        {
            if(is_zheng(t))
                get_frac(-b+int(t),2*a,0);
            else
            {
                get_frac(-b,2*a,1);
                int zhengfu=1;
                if(t<0) t=-t,zhengfu=-1;
                wai=Solve(derta),nei=derta/wai/wai;
                //cout<<"derta="<<derta<<" t="<<t<<" wai="<<wai<<" nei="<<nei<<endl;
                wai*=zhengfu;
                if(is_zheng((double)wai/(2*a)))
                {
                    if(wai/(2*a)!=1) printf("%d*",wai/(2*a));
                    printf("sqrt(%d)",nei);
                }
                else
                    get_frac(wai,2*a,2);
            }
            printf("\n");
        }
    }
    return 0;
}