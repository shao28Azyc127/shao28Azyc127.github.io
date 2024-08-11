#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long a,b,c;
    long long x,y,v;
    cin>>x>>y;
    for(v=0;v<x;v++)
    {
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(long long i=0;i<y;i++)
        {
            if(a*v*v+b*v+c==0)
            {
                cout<<v<<endl;
                continue;
            }
        }
        return 0;
}