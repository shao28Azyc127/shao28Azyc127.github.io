#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005];
int c[5005];
int gc(int p,int j)
{
    int ma=0;
    for(int i=1;i<=min(p,j);i++)
    {
        if(p%i==0&&j%i==0)
            ma=i;
    }
    return ma;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(b[i]*b[i]-4*a[i]*c[i]<0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(c[i]==0)
            {
                if(b[i]==0)
                {
                    cout<<0<<endl;
                }
                else
                {
                    double p=b[i]/a[i]*(-1);
                    if(p>0)
                    {
                        if(b[i]%a[i]==0)
                            cout<<(-1)*b[i]/a[i]<<endl;
                        else
                        {
                            if(b[i]<0)
                            {
                                b[i]=-b[i];
                            }
                            if(a[i]<0)
                            {
                                a[i]=-a[i];
                            }
                            //cout<<'*'<<b[i]<<' '<<a[i]<<' '<<gc(a[i],b[i])<<endl;
                            cout<<b[i]/gc(a[i],b[i])<<"/"<<a[i]/gc(a[i],b[i])<<endl;
                        }

                    }
                    else
                        cout<<0<<endl;
                }
            }
            else
             {
                 if(b[i]==0)
                 {
                     int r=(-1)*c[i]/a[i];

                        cout<<sqrt(r)<<endl;
                 }
                 else
                    cout<<endl;
             }
        }
    }
    return 0;
}
