#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    bool f=1;
    int z=0,r;
    while(f==1)
    {
        ++z;
        f=0;
        for(int i=1;i<=n;++i)
        {
            if(a[i]==0)
            {
                if(i==n)
                {
                    r=z;
                }
                a[i]=1;
                //cout<<"*"<<i<<endl;
                int o=2;
                while(o>0)
                {
                    o--;
                    i++;
                    if(a[i]==1)
                        o++;
                }
            }
            else
            {
                continue;
            }
        }

        for(int i=1;i<=n;++i)
        {
            if(a[i]==0)
            {
                f=1;
            }
        }

    }
    cout<<z<<' '<<r;
    return 0;
}
