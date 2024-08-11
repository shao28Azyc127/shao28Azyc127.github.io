#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1;
int n,d,v[N],a[N],pre[N],minn=2e9,point=1,ans=0,cnt=0;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i+1];
        pre[i+1]=pre[i]+v[i+1];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            minn=a[1];
        }
        //cout<<minn<<' ';
        if(i==n){
            int j=(pre[i]-pre[point])-cnt;
            int reg=j/d;
            int rej=j%d;
            //cout<<point<<' '<<i<<' '<<(reg+(rej!=0))*minn;
            ans+=(reg+(rej!=0))*minn;
            cnt=(reg+(rej!=0))*d-j;
        }else if(a[i]<minn){
            int j=(pre[i]-pre[point])-cnt;
            int reg=j/d;
            int rej=j%d;
            //cout<<point<<' '<<i<<' '<<(reg+(rej!=0))*minn;
            ans+=(reg+(rej!=0))*minn;
            cnt=(reg+(rej!=0))*d-j;
            point=i;
            minn=a[i];
        }
        //cout<<'\n';
    }
    cout<<ans;
    return 0;
}
