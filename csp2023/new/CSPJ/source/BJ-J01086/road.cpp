#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],b[100005];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++) scanf("%lld",a+i);
    for(int i=1;i<=n;i++) scanf("%lld",b+i);
    b[n]=0;
    int nowx=1,ll=0,cnt=0,ans=0;
    for(int i=2;i<=n;i++){
        cnt+=a[i-1];
        if(b[i]<b[nowx]){
            int tmp=cnt-ll;
//            cout<<nowx<<" "<<cnt<<" "<<ll<<endl;
            tmp=(tmp%d==0?tmp/d:tmp/d+1);
//            cout<<nowx<<" "<<tmp<<endl;
            if(tmp<0) tmp=0;
            ans+=tmp*b[nowx];
            nowx=i;
            ll=tmp*d-cnt+ll;
            cnt=0;
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
