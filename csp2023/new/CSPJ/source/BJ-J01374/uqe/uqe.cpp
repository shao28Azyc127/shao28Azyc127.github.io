// ¹Ø×¢¼ÎÈ»ß÷£¬¹Ø×¢¼ÎÈ»Ð»Ð»ß÷¡«

#include<bits/stdc++.h>
using namespace std;
bool outputtag=0;
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
void printdiv(int a,int b)
{
    int minutag=0;
    if(a<0) a=-a,minutag^=1;
    if(b<0) b=-b,minutag^=1;

    int g=gcd(a,b);
    a/=g,b/=g;
    if(a==0) return ;
    if(minutag) putchar('-');
    if(b==1)
    {
        outputtag=1;
        printf("%d",a);
        return ;
    }
    outputtag=1;
    printf("%d/%d",a,b);
}
bool square(int a)
{
    int minu=sqrt(a);
    if(minu*minu==a) return true;
    return false;
}
void work(int a,int b,int c)
{
    if(a<0)
    {
        a=-a,b=-b,c=-c;
    }
    outputtag=0;
    int delta=b*b-4*a*c;
    if(delta<0)
    {
        puts("NO");return ;
    }else if(square(delta)){
        printdiv(-b+sqrt(delta),2*a);
    }else{
        printdiv(-b,2*a);
        int nows=1;
        for(int i=2;i*i<=delta;i++)
        {
            if(i*i>delta) break;
            while(delta%(i*i)==0)
            {
                nows*=i;
                delta/=(i*i);
            }
        }
        int g=gcd(nows,2*a);
        nows/=g;
        int p=2*a;
        p/=g;
        if(outputtag) putchar('+');
        if(nows==1)
        {
            printf("sqrt(%d)",delta);
        }else{
            printf("%d*sqrt(%d)",nows,delta);
        }

        outputtag=1;
        if(p!=1)
        {
            printf("/%d",p);
        }
    }
    if(outputtag==0)
    {
        putchar('0');
    }
    putchar('\n');
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    scanf("%d%d",&T,&M);
    while(T--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        work(a,b,c);
    }
    return 0;
}
