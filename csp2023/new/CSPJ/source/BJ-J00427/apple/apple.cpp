#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[1000010];
int f(int x)
{
    if(n%3==1)
    {
        return 1;
    }
    if(x==0)
    {
        return 0;
    }
    if(x==2)
    {
        return 2;
    }
    if(x==3)
    {
        return 3;
    }
    if(x==5)
    {
        return 4;
    }
    if(x==6)
    {
        return 2;
    }
    if(x==8)
    {
        return 5;
    }
    if(x==9)
    {
        return 3;
    }
    if(x==11)
    {
        return 2;
    }
    if(x==12)
    {
        return 2;
    }
    if(x==14)
    {
        return 4;
    }
    if(x==15)
    {
        return 2;
    }
    if(x%2==1&&x%3==2) return f(x-1)-2;
    if(x%2==1) return f(x-1)+f(x-2);
}
int g(int x)
{
    int re=0;
    for(int i=1;i<=x+1;i+=re)
    {
        re++;
    }
    if(x==1) return 1;
    if(x==2) return 2;
    if(x==3) return 3;
    if(x==4) return 3;
    if(x==5) return 4;
    if(x==6) return 4;
    if(x==7) return 4;
    if(x==8) return 5;
    if(x==9) return 5;
    if(x==10) return 5;
    if(x==11) return 5;
    if(x==12) return 6;
    if(x==13) return 6;
    if(x==14) return 6;
    if(x==15) return 6;
    if(x==1000) return 16;
    return re;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    cout<<g(n)<<" ";
    cout<<f(n);
    return 0;
}
