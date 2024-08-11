#include<bits/stdc++.h>
using namespace std;
int pand(int r)
{
    for(int i=1;i<=sqrt(r);i++)
    {
        if(i*i==r)
            return i;
    }
    return 0;
}
int gcd(int xs,int xx)
{
    if(xs==xx)
        return xs;
    int i=xs-xx;
    if(i<0)
        i=0-i;
    if(xs%i==0&&xx%i==0)
        return i;
    if(xs>xx)
        gcd(i,xx);
    if(xx>xs)
        gcd(xs,i);
}
void youli(int xs,int xx)
{
    int i=gcd(xs,xx);
    if(xs%xx==0)
        cout<<xs/xx<<endl;
    else
        cout<<xs/i<<"/"<<xx/i<<endl;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int sj=b*b-(4*a*c);
        if(sj<0)
            cout<<"NO"<<endl;
        if(sj==0)
            youli(0-b,2*a);
        if(sj>0)
        {
            if(pand(sj)!=0)
                youli(sqrt(sj)-b,2*a);
        }
    }
    return 0;
}