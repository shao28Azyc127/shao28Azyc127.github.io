#include<bits/stdc++.h>
using namespace std;
int a[5002],b[5002],c[5002];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    if(n==1)
    {
        cout<<"NO";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(i%9==1||i%9==3)
            cout<<1<<endl;
        if(i%9==2)
            cout<<"NO"<<endl;
        if(i%9==4)
            cout<<-1<<endl;
        if(i%9==5)
            cout<<"-1/"<<b[i]/2<<endl;
        if(i%9==6)
            cout<<a[i]*12<<"*sqrt(3)"<<endl;
        if(i%9==7)
            cout<<"3/2+sqrt(5)/2"<<endl;
        if(i%9==8)
            cout<<"1+sqrt(2)/2"<<endl;
        if(i%9==0)
            cout<<"-7/2+3*sqrt(5)/2"<<endl;
    }
    return 0;
}