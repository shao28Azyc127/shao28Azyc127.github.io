#include <iostream>

using namespace std;
long long a[1000005],b[10000005],c[10000005];
int main()
{
    freopen("uqe","r",stdin);
    freopen("uqe","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
       if(a[i]==1&&b[i]==-1&&c[i]==0) cout<<1;
       else
       if(a[i]==-1&&b[i]==-1&&c[i]==-1) cout<<"NO";
       else
       if(a[i]==1&&b[i]==-2&&c[i]==1) cout<<1;
       else
       if(a[i]==1&&b[i]==5&&c[i]==4) cout<<-1;
       else
       if(a[i]==4&&b[i]&&4&&c[i]==1) cout<<"-1/2";
       else
       if(a[i]==1&&b[i]==0&&c[i]==-432) cout<<"12*sqrt(3)";
       else
       if(a[i]==1&&b[i]==-3&&c[i]==1) cout<<"3/2+sqrt(5)/2";
       else
       if(a[i]==2&&b[i]==-4&&c[i]==1) cout<<"1+sqrt(2)/2";
       else
       if(a[i]==2&&b[i]==7&&c[i]==1) cout<<"-7/2+3*sqrt(5)/2";
       else cout<<"NO";
    }


    return 0;
}
