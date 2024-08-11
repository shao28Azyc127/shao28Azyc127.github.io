#include<bits/stdc++.h>
using namespace std;
double a[5005][4];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];

    }
for(int i=1;i<=t;i++)
    {

        if(m==1)
        {
            if(a[i][2]==0 and a[i][3]==0)
            {
                if(a[i][1]==1 or a[i][1]==-1)
                {
                    cout<<0<<endl;
                    continue;
                }
            }
        }
        double q=a[i][2]*a[i][2]-4*a[i][1]*a[i][3];
        if(q<0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(q=0)
            {


                cout<<(-a[i][2]+q)/2*a[i][1]<<endl;
            }
            else
            {
                int x=(-a[i][2]+q)/2*a[i][1];
                int y=(-a[i][2]-q)/2*a[i][1];
                if(x>y)
                {
                    cout<<x<<endl;
                }
                else
                {
                    cout<<y<<endl;
                }
            }
        }
    }
    return 0;
}