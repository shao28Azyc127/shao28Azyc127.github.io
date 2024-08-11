/*
你指尖跃动着的电光，是我此生不变的信仰，唯有我超电磁炮永世长存！
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=1e5+10;
int n,d;
int v[Maxn],a[Maxn];
int pre[Maxn];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n-1;i++) scanf("%lld",&v[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    pre[1]=0;
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1]+v[i-1];
    }
    int dist=0;
    for(int i=1;i<=n-1;i++)
    {
        dist+=v[i];
    }
    int totaloil=dist/d+(dist%d!=0);
    int ans=0;
    int now=1;
    int oilcango=0;
    int cnt=0;
    while(now<n)
    {
        int minid=n;
        int aimdist=pre[minid]-pre[now]-oilcango;
        int needoil=(aimdist)/d+(aimdist%d!=0);
        for(int i=now+1;i<=minid;i++)
        {
            int dist1=pre[i]-pre[now]-oilcango;
            int ndo1=(dist1)/d+(dist1%d!=0);
            int dist2=pre[minid]-pre[i]-(ndo1*d-dist1);
            int ndo2=(dist2)/d+(dist2%d!=0);
            if((ndo1)*a[now]+ndo2*a[i]<=needoil*a[now])
            {
                minid=i;
                aimdist=pre[minid]-pre[now]-oilcango;
                needoil=(aimdist)/d+(aimdist%d!=0);
            }
        }
        if(pre[minid]-pre[now]<=oilcango)
        {
            oilcango-=(pre[minid]-pre[now]);
            now=minid;
            continue;
        }
        //cout<<"now="<<now<<endl;
        ans+=needoil*a[now];
        now=minid;
        //cout<<"goto "<<minid<<endl;
        oilcango=needoil*d-aimdist;
        //cout<<"needoil="<<needoil<<endl;
        //cout<<"oilcango="<<oilcango<<endl;
    }
    printf("%lld\n",ans);
    return 0;
}

