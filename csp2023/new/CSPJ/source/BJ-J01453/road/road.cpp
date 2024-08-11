#include<bits/stdc++.h>
using namespace std;
int f[100005];
int k[100005];
int n,d,v[100005],a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    memset(f,0x3f3f3f3f,sizeof(f));
    f[1]=0;
    for(int i=1;i<n;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)
    {
        int l=0;
        for(int j=i-1;j>=1;j--)
        {
            l+=v[j];
            int s=(l-k[j])/d;
            if(s*d<(l-k[j])) s+=1;
            if(f[i]>f[j]+s*a[j])
            {
                f[i]=min(f[i],f[j]+s*a[j]);
                k[i]=s*d+k[j]-l;
            }
        }
    }
    printf("%d",f[n]);
    return 0;
}
