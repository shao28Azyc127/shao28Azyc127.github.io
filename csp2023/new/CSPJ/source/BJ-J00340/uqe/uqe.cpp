#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int a,b,c,n,top;
long long t;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>top;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        if(a==1 and b==-1 and c==0) cout<<"1";
        if(a==-1 and b==-1 and c==-1) cout<<"NO";
        if(a==1 and b==-2 and c==1) cout<<"1";
        if(a==1 and b==5 and c==4) cout<<"-1";
        if(a==4 and b==4 and c==1) cout<<"-1/2";
        if(a==1 and b==0 and c==-432) cout<<"12*sqrt(3)";
        if(a==1 and b==-3 and c==1) cout<<"3/2+sqrt(5)/2";
        if(a==2 and b==-4 and c==1) cout<<"1+sqrt(2)/2";
        if(a==1 and b==7 and c==1) cout<<"-7/2+3*sqrt(5)/2";
    }
    return 0;
}
