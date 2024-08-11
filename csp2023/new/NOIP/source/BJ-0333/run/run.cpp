#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m,k,d;
int ca[300][4];
int road[300];
long long ans = 0;
int rcd[300];
int sum[300];
long long check()
{
    long long alco = d*sum[n];
    long long tp = 0;
    for(int i = 1; i <= m; i++){
        if(sum[ca[i][1]]-sum[ca[i][1]-ca[i][2]]==ca[i][2])tp+=ca[i][3];
    }

    return tp-alco;

}
void dfs(int x,int l)
{
    if(x==n){
        ans = max(ans,check());return;
    }
    if(road[x+1]==0){
        dfs(x+1,0);
    }
    else{
        if(l<k){
            rcd[x+1] = 1;
            sum[x+1] = 1;
            sum[x+1]+=sum[x];
            dfs(x+1,l+1);
        }
        rcd[x+1] = 0;
        sum[x+1] = sum[x];
        dfs(x+1,0);
    }
    return;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    for(int i = 1; i <= t; i++){
        cin>>n>>m>>k>>d;
        memset(ca,0,sizeof(ca));
        memset(sum,0,sizeof(sum));
        memset(road,0,sizeof(road));
        memset(rcd,0,sizeof(rcd));
        for(int j = 1; j <= m; j++){
            cin>>ca[j][1]>>ca[j][2]>>ca[j][3];
            for(int k = ca[j][1]-ca[j][2]+1; k <= ca[j][1]; k++){
                road[k] = 1;
            }
        }
        ans = 0;
        dfs(0,0);
        cout<<ans<<endl;
    }

    return 0;
}
