#include<bits/stdc++.h>
using namespace std;
int s;
long long n,day=0,ans=0,x;
bool a[1000050000];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(x!=n)
    {
        x=0;
        s=3;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(s==3)
                {
                    a[i]=1;
                    s=0;
                }
                s++;
            }
            if(a[i]==1)
                x++;
        }
        day++;
        if(a[n]==1&&ans==0)
            ans=day;
    }
    cout<<day<<" "<<ans;
    return 0;
}
