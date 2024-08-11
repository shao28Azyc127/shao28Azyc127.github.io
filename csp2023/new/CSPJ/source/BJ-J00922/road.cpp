#include<bits/stdc++.h>
using namespace std;
int a[100020][3];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int yx=0,n,d,sum=0,t=1;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
        cin>>a[i][1];
    for(int i=1;i<=n;i++)
        cin>>a[i][2];
    int i=1;
    while(i<n)
    {
        if(a[i][2]>=a[i+t][2])
        {
            int jl=0;
            for(int j=i;j<=i+t-1;j++)
            {
                jl+=a[j][1];
            }
            int c=(jl-yx)/d;
            if((jl-yx)%d!=0)
                c++;
            yx+=c*d;
            sum+=c*a[i][2];
            i+=t;
            t=1;
            yx-=jl;
        }
        else
        {
            t++;
            if(i+t==n)
            {
                int jl=0;
                for(int j=i;j<=n-1;j++)
                {
                    jl+=a[j][1];
                }
                int c=(jl-yx)/d;
                if((jl-yx)%d!=0)
                    c++;
                yx+=c*d;
                sum+=c*a[i][2];
                i+=t;
                yx-=jl;
            }
        }
    }
    cout<<sum;
    return 0;
}