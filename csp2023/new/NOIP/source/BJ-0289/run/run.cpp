#include<bits/stdc++.h>
#define ll long long
const int N=100010;
ll c,t;
ll n,m,k,d,cnt;
struct node{
    ll x,y,z;
}a[N];
ll ex[1010][1010];
ll dp[1010][2];
using namespace std;
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m>>k>>d;
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                ex[i][j]=-(j-i+1)*d;
        for(int i=0;i<=n;i++)
            dp[i][0]=dp[i][1]=0;
        for(int i=1;i<=m;i++){
            ll x,y,z;
            cin>>x>>y>>z;
            a[i].x=x;
            a[i].y=y;
            a[i].z=z;
            for(int j=x-y+1;j>=0;j--){
                for(int k=x;k<=n;k++){
                    ex[j][k]+=z;
                }
            }
        }
        /*for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                cout<<ex[i][j]<<endl;*/
        for(int i=1;i<=n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i][0];
            for(int j=i-k;j<i;j++){
                dp[i][1]=max(dp[i][1],dp[j][0]+ex[j+1][i]);
            }
        }
        cout<<max(dp[n][0],dp[n][1])<<endl;
    }
    return 0;
}
