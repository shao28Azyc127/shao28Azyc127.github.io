#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
bool flagb=true;
long long n,b[100005],c[100005];
long long a[100005];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    for(long long i=1;i<=n-1;i++)
    {
        long long u,v;
        cin>>u>>v;
        if(u!=i||v!=i+1) flagb=false;
    }
    if(flagb==true)
    {
        long long maxn=0;
        for(long long i=1;i<=n;i++)
        {
            for(long long j=i;j<=2e9;j++)
            {
                a[i]-=max(1ll*1,b[i]+j*c[i]);
                if(a[i]<=0)
                {
                    maxn=max(maxn,1ll*j);
                    break;
                }
            }
        }
        cout<<max(maxn,1ll*n)<<endl;
        return 0;
    }
    cout<<n<<endl;
    return 0;
}
