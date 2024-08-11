#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a==0) return b;
    return gcd(b%a,a);
}
void printdiv(int a,int b)
{
    if((long long)a*b<0) putchar('-');
    a=abs(a),b=abs(b);
    int gcdba=gcd(b,a);
    a/=gcdba,b/=gcdba;
    printf("%d",a);
    if(b-1) printf("/%d",b);
}
void printsqrt(int b,int sqrtc)
{
    int a=1;
    for(int i=2;i<=sqrt(sqrtc);i++)
    {
        while(sqrtc%(i*i)==0)
        {
            a*=i;
            sqrtc/=(i*i);
        }
    }
    int gcdba=gcd(b,a);
    a/=gcdba,b/=gcdba;
    if(a-1) printf("%d*",a);
    printf("sqrt(%d)",sqrtc);
    if(b-1) printf("/%d",b);
}
void print(int a,int b,int sqrtc=-1)
{
    if(sqrtc==-1) printdiv(a,b);
    else printsqrt(b,sqrtc);
}
signed main()
{
    int T,m;
    scanf("%d%d",&T,&m);
    while(T--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a<0) a=-a,b=-b,c=-c;
        int dt=b*b-(a*c<<2);
        if(dt<0) printf("NO");
        else if(dt==0) print(-b,a<<1);
        else
        {
            if(((int)sqrt(dt))*((int)sqrt(dt))==dt) print(-b+sqrt(dt),a<<1);
            else
            {
                if(b!=0)
                {
                    print(-b,a<<1);
                    putchar('+');
                }
                print(0,a<<1,dt);
            }
        }
        putchar('\n');
    }
    return 0;
}
