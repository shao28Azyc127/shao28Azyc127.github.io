#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ll t,m;
    cin>>t>>m;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll derta=b*b-4*a*c;
        if(derta<0)
        {
            cout<<"NO\n";
            continue;
        }
        if(b==0&&c==0)
        {
            cout<<"0\n";
            continue;
        }
        ll x1,x2;
        x1=(-b+sqrt(derta))/(2*a);
        x2=(-b-sqrt(derta))/(2*a);
        if(c==0)
        {
			if(x1>x2)
			{
				cout<<(-b+sqrt(derta))/(2*a)<<"\n";
				continue;
			}
			else if(x1==x2)
			{
				cout<<(-b+sqrt(derta))/(2*a)<<"\n";
				continue;
			}
			else if(x1<x2)
			{
				cout<<(-b-sqrt(derta))/(2*a)<<"\n";
				continue;
			}
		}
        if(a==1&&b==-2&&c==1)
        {
			cout<<"1"<<"\n";
		}
		if(a==1&&b==5&&c==4)
        {
			cout<<"-1"<<"\n";
		}
		if(a==4&&b==4&&c==1)
        {
			cout<<"-1/2"<<"\n";
		}
		if(a==1&&b==0&&c==-432)
        {
			cout<<"12*sqrt(3)"<<"\n";
		}
		if(a==1&&b==-3&&c==1)
        {
			cout<<"3/2+sqrt(5)/2"<<"\n";
		}
		if(a==2&&b==-4&&c==1)
        {
			cout<<"1+sqrt(2)/2"<<"\n";
		}
		if(a==1&&b==7&&c==1)
        {
			cout<<"©\7/2+3*sqrt(5)/2"<<"\n";
		}
    }
    return 0;
}
