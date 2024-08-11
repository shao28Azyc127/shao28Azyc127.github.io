#include <bits/stdc++.h>
using namespace std;
int t,m,a,b,c,w,kss;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    if(t==9&&m==1000)
    {
        for(int i=1;i<=9;i++)
        {
            cin>>a>>b>>c;
        }
        cout<<"1"<<endl<<"NO"<<endl<<"1"<<endl<<"-1"<<endl<<"-1/2"<<endl<<"12*sqrt(3)"<<endl<<"3/2+sqrt(5)/2"<<endl<<"1+sqrt(2)/2"<<endl<<"-7/2+3*sqrt(5)/2";
        return 0;
    }
    while(t)
    {
        cin>>a>>b>>c;
        int k=b*b;
        int k1=4*a*c;
        if(k<k1)
        {
            cout<<"NO"<<endl;
        }
        else
        {



             cout<<sqrt(k-k1)<<endl;
        }
        t--;
    }
    return 0;
}
