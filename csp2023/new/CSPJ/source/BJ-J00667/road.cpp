#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define mod 1000000007
using namespace std;
int n,d;
int v[100010],cost[100010];
int sum[100010];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>d;
    sum[1]=0;
    for(int i=2;i<=n;i++){
        cin>>v[i];
        sum[i]=sum[i-1]+v[i];
    }
    for(int i=1;i<=n;i++)cin>>cost[i];
    cost[n]=-1;
    int c=cost[1],x=1;
    int ans=0,f=0;
    for(int i=2;i<=n;i++){
        if(c>cost[i]){
            int f1=f;
            f+=(sum[i]-sum[x])/d;
            while(f*d<sum[i])f++;
            ans+=(f-f1)*c;
            c=cost[i],x=i;
        }
    }
    cout<<ans;
    return 0;
}
