#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define doil ((double)v[i]/d)
#define iceil(x) int(ceil(x))
#define getoil (iceil((double)(vps[i]-vps[mnidx]-oom[mnidx])/d)*(double)mnai)
#define realdt (double)(vps[i]-vps[mnidx]-oom[mnidx])
#ifndef DEBUG_F
#define DEBUG_F false
#endif
#define DBG if(DEBUG_F)
using namespace std;
int n,d;
long long cost[114514]; // station i use oil j min cost
// remod dp[i][j][k] station i can walk j dt, add oil from i-1? cost
// mod dp[i][j][kj] station i use j cost add oil from i-1? val the oil
long long v[114514],a[114514];
long long oom[114514]; // rong yu dist
long long vps[114514]; // prefix sum of v
int main(){
    //#ifndef ONLINE_JUDGE
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //#endif
    long long mxoil=10;
    scanf("%d%d",&n,&d);
    for(int i=2;i<=n;++i){
        scanf("%lld",v+i);
        mxoil+=v[i];
        vps[i]=vps[i-1]+v[i];
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",a+i);
    }
    mxoil/=d;
    mxoil++;
    //printf("mxoidl %lld\n",mxoil);
    //return 0;
    int day=1,outans=0;
    int cn=n;
    int mnai=a[1],mnidx=1;
    //memset(dp,0x3f,sizeof(dp));
    //for(int j=0;j<=mxoil;++j)dp[1][j][0]=dp[1][j][1]=a[1]*j;
    for(int i=2;i<=n;++i){
        cost[i]=cost[mnidx]+getoil;
        //oom[i]=getoil%d;
        // getoil/mnai = real dist mn<->i;
        oom[i]=abs((double)(cost[i]-cost[mnidx])*(double)d/(double)mnai-realdt);
        if(a[i]<mnai){
            mnidx=i;
            mnai=a[i];
        }
    }
    long long ans=0x3f3f3f3f3f3f3f3f;
    printf("%lld\n",cost[n]);
    return 0;
}