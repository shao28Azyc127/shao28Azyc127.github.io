#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c,x;
int gcd(int a1,int a2)
{
    int f,n=0;
    if(a1<a2)
    {
        f=a1;
    }
    else
    {
        f=a2;
    }
    for(int i=1;i<f;i++)
    {
        if(a1%i==0&&a2%i==0)
        {
            n++;
        }
        if(n>1)
        {
            return 0;
        }
    }
    return 1;
}
int xxx(int a1)
{
    int q,qq;
    if(a1>0)
    {
        for(int i=1;i<=a1;i++)
        {
            if(gcd(i,a1*i))
            {
                q++;
                qq=i;
            }
            if(q>1)
            {
                return 0;
            }
        }
        return qq;
    }
    if(a1<0)
    {
        for(int i=-1;i>=a1;i--)
        {
            if(gcd(i,i/a1))
            {
                q++;
                qq=i/a1;
            }
            if(q>1)
            {
                return 0;
            }
        }
        return qq;
    }
}
int main()
{
    cin>>t>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        if((b*b)-4*a*c<0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(((0-b)+sqrt((b*b)-4*a*c))/2*a<((0-b)-sqrt((b*b)-4*a*c))/2*a)
            {
                x=((0-b)-sqrt((b*b)-4*a*c))/2*a;
            }
            else
            {
                x=((0-b)+sqrt((b*b)-4*a*c))/2*a;
            }
            if(xxx(x)==1)
            {
                cout<<x*xxx(x)<<endl;
            }
            else if(xxx(x))
            {
                cout<<x*xxx(x)<<" "<<xxx(x)<<endl;;
            }
        }
    }
}
