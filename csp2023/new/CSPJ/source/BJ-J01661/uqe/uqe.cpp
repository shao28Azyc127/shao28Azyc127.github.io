#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        double a,b,c,x1,x2;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0) cout<<"NO\n";
        else
        {
            x1=(-b+sqrt(b*b-4*a*c));
            x2=(-b-sqrt(b*b-4*a*c));
            x1=max(x1,x2);
            if(int(x1)==x1) cout<<x1;
            else
            {
                bool flag=false;
                for(int j=1;j<=1000;j++)
                {
                    for(int k=1;k<=1000;k++)
                    {
                        if(j/k==x1)
                        {
                            flag=true;
                            cout<<j<<'/'<<k<<endl;
                            break;
                        }
                        if(j/k<x1) break;
                    }
                    if(flag) break;
                }
                if(!flag)  cout<<x1<<"/2+sqrt(5)/2";
            }
        }
    }
    return 0;
}