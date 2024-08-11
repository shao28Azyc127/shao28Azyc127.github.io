#include<bits/stdc++.h>
#define dd double
using namespace std;
int t,m;
bool ck_int(dd n)
{
    if(n==int(n)) return true;
    else return false;
}
void dcout(dd n)
{
    if(ck_int(n)==true)
    {
        cout<<n;
        return;
    }
    for(int i=2;i<=int(m/n+1);i++)
    {
        if(ck_int(n*i)==true)
        {
            cout<<i<<"/"<<n*i;
            cout<<"m";
        }
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dd ls=b*b-4*a*c;
        if(ls<0)
        {
            cout<<"NO\n";
            continue;
        }
        dd an1,an2;
        an1=(-b+sqrt(ls))/2*a;
        an2=(-b-sqrt(ls))/2*a;
        if(ck_int(sqrt(ls))) dcout(an1);
        if(ck_int(sqrt(ls))) dcout(an2);
        cout<<endl;
    }
    return 0;
}
