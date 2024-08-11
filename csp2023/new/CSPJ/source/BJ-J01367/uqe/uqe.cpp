#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
int t,m;
int x,y,z,w,v;
void sxy()
{
    for(int i=2;i<=m;i++)
    {
        int x_=abs(x),y_=abs(y);
        if(x_<i||y_<i)break;
        if(x_%i==0&&y_%i==0)
        {x/=i;y/=i;i--;}
    }
    if(y<0){x=(-x);y=(-y);}
}
void swz()
{
    for(int i=2;i<=m;i++)
    {
        if(w<i*i)break;
        if(w%i*i==0)
        {w/=i*i;z*=i;i--;}
    }
}
void szv()
{
    for(int i=2;i<=m;i++)
    {
        int z_=abs(z),v_=abs(v);
        if(z_<i||v_<i)break;
        if(z_%i==0&&v_%i==0)
        {z/=i;v/=i;i--;}
    }
    if(v<0)v=(-v);
}
void coutf()
{
    if(w==1)
    {x*=v;x+=z*y;w=0;sxy();}
    if(x!=0)
    {
        cout<<x;
        if(y!=1)
        cout<<"/"<<y;
        cout<<"+";
    }
    if(w!=0&&w!=1)
    {
        cout<<z<<"*sqrt("<<w<<")";
        if(v!=1)
        cout<<"/"<<v;
    }
    if(w==1)
    {
        cout<<z;
        if(v!=1)
        cout<<"/"<<v;
    }
    if(w==0&&x==0)cout<<0;
    cout<<endl;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=0;i<t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        w=b*b-4*a*c;
        v=2*a;z=1;
        x=(-b);y=2*a;
        if(w<0){cout<<"NO"<<endl;continue;}
        sxy();swz();szv();
        coutf();
    }
    return 0;
}