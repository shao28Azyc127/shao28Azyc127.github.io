#include<iostream>
using namespace std;
int t,m,a[5005],b[5005],c[5005];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=t;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(a[i]*j*j+b[i]*j+c[i]==0)
            {
                cout<<j<<endl;
                break;
            }
        }
    }
    return 0;
}
