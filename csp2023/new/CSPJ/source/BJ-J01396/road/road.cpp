#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define _for1(i,a,b) for(int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int n,d;
const int maxn=1e5+5;
int a[maxn],v[maxn],s[maxn];
int now=0,ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    ms(a,0x3f);
    _for(i,1,n-1)
        scanf("%d",&v[i]);
    _for(i,1,n)
        scanf("%d",&a[i]);
    s[1]=v[1];
    _for(i,2,n-1) s[i]=s[i-1]+v[i];
//    _for(i,1,n-1) cout<<s[i]<<endl;
//    _for(i,1,n) cout<<v[i]<<endl;xiao-da
    int i=1;
    while(i<=n)
    {
        int j=1;
        for(j=i;j<=n;j++)
        {
            if(a[j]<a[i])
            {
                //cout<<j;
                break;
            }
        }
        if(a[j]>=a[i])
        {
            //cout<<"nb\n";
            int t=s[n-1]-s[i-1];
            t-=now;
            now=0;
            if(t%d==0) ans+=(t/d)*a[i];
            else ans+=(t/d+1)*a[i],now=t%d;
            break;
        }
        int t=s[j-1]-s[i-1];
        t-=now;
        now=0;
        if(t%d==0) ans+=(t/d)*a[i];
        else ans+=(t/d+1)*a[i],now=t%d;
        i=j;
    }
    cout<<ans<<endl;
    return 0;
}
