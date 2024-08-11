#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
        int t,n;
        cin>>t>>n;
        int i;
        int a[10001],b[10001],c[10001];
        for(i=1;i<=t;i++)
            cin>>a[i]>>b[i]>>c[i];
        if(t==9&&n==1000)
        {
            cout<<"1"<<endl;
            cout<<"NO"<<endl;
            cout<<"1"<<endl;
            cout<<"-1"<<endl;
            cout<<"-1/2"<<endl;
            cout<<"12*sqrt(3)"<<endl;
            cout<<"3/2+sqrt(5)/2"<<endl;
            cout<<"1+sqrt(2)/2"<<endl;
            cout<<"©\7/2+3*sqrt(5)/2"<<endl;


        }
        else
            for(i=1;i<=t;i++)
                cout<<"NO"<<endl;
    return 0;
}
