#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int bet,cet;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a[5005],b[5005],c[5005],x=0;
    cin>>t>>m;
    for(int i = 0;i<t;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i = 0;i<t;i++)
    {
        bool flag = true;
        if(b[i]==0&&c[i]==0)
        {
            cout<<0<<endl;
            flag=false;
        }
        int al=b[i]*b[i]-4*a[i]*c[i];
        if(al<0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            bet=(-b[i]+sqrt(al))/2;
            cet=(-b[i]-sqrt(al))/2;
        }
        if(bet>cet&&flag == true&&al==1||al==0)
            cout<<(0-b[i]+1)/2<<endl;
        else if(bet<=cet&&flag == true&&al==1||al==0)
            cout<<(0-b[i]-1)/2<<endl;
        else if(bet>cet&&flag == true)
            cout<<0-b[i]<<"+"<<"sqrt("<<al<<")/2"<<endl;
        else if(bet<=cet&&flag == true)
            cout<<0-b[i]<<"-"<<"sqrt("<<al<<")/2"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

