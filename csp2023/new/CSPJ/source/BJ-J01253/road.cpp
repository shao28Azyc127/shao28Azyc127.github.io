#include<bits/stdc++.h>
using namespace std;
long long n,d,a[101010],b[101010],s[101010],ans;
int main()
{
    //2 27      3 45         3 60
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    long long l=1,r=1,you=0;
    while(1)
    {
        r++;
        if(r==n)
        {
            long long ttt;
            if((s[n-1]-s[l-1]+you)%d==0)
            {
                ttt=b[l]*((s[n-1]-s[l-1])/d);
                you=0;
            }
            else
            {
                if((s[r-1]-s[l-1])%d==0) ttt=b[l]*((s[r-1]-s[l-1])/d);
                else ttt=b[l]*((s[r-1]-s[l-1]-you)/d+1);
                you=(s[r-1]-s[l-1]+you)%d;
            }
            ans+=ttt;
            cout<<ans;
            return 0;
        }
        if(b[l]>b[r])
        {
            long long ttt;
            if((s[r-1]-s[l-1]+you)%d==0)
            {
                ttt=b[l]*((s[r-1]-s[l-1])/d);
                you=0;
            }
            else
            {
                if((s[r-1]-s[l-1])%d==0) ttt=b[l]*((s[r-1]-s[l-1])/d);
                else ttt=b[l]*((s[r-1]-s[l-1]-you)/d+1);
                you=(s[r-1]-s[l-1]+you)%d;
                //cout<<b[l]<<" "<<((s[r-1]-s[l-1]+you)/d)<<" ";
            }
            ans+=ttt;
            l=r;
            //cout<<ans<<" \n\n\n";
            //cout<<endl;
        }
    }
    return 0;
}
