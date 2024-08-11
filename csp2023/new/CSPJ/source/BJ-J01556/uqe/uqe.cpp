#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,temp=0,shak=0,tar=0;
    cin>>t>>m;
    for(int i=1; i<=t; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b==0&&c!=0)
        {
            shak++;
            cout<<sqrt(-c/a);
        }
        if(b==0&&c==0)
        {
            temp++;
            if(a==0)
            {
                cout<<0;
            }
            if(a==1)
            {
                 cout<<1;
            }
        }
        if(temp==0&&shak==0&&tar==0)
        {
            if(b*b-4*a*c<0)
            {
                cout<<"NO";
            }
        }
    }
}
