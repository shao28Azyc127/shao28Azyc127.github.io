#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,d;
int v[maxn];
int a[maxn],mina[maxn];
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%d",&v[i]);
    }
    mina[0]=2147483647;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mina[i]=min(mina[i-1],a[i]);
    }
    int s=0;
    for(int i=1;i<n;i++){
        int vv=v[i];
        vv-=s;
        s=0;
        ans+=mina[i]*(vv/d);
        if(vv%d!=0){
            ans+=mina[i];
            s+=(vv/d+1)*d-vv;
        }
    }
    printf("%lld",ans);
}
