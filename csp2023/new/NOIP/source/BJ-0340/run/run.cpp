#include <bits/stdc++.h>
using namespace std;
int n,m,k,d;
int c,t;
vector<pair<int,long long> > w[1005];
long long f[1005][1005];
long long ans;

long long C(int x,int y){
    long long res=0;
    for(int i=0;i<w[x].size();i++){
        if(w[x][i].first >y){
            break;
        }
        res+=w[x][i].second;
    }
    return res;
}

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(f,0xFE,sizeof(f));
        ans=0;
        for(int i=0;i<=1004;i++){
            w[i].clear();
        }
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            int x,y,v;
            cin>>x>>y>>v;
            w[x].push_back(make_pair(y,v));
        }
        for(int i=1;i<=n;i++){
            sort(w[i].begin(),w[i].end());
        }
        f[0][0]=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=(k-1);j++){
                f[i+1][0]=max(f[i+1][0],f[i][j]);//not run at i+1
                f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+C(i+1,j+1)-d);//not run at i+1
                //cerr<<C(i,j+1)<<" \n"[j==k-1];
            }
            f[i+1][0]=max(f[i+1][0],f[i][k]);//not run at i+1
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                //cerr<<f[i][j]<<" \n"[j==k];
            }
        }
        for(int i=0;i<=k;i++){
            //cout<<f[n][i]<<endl;
            ans=max(ans,f[n][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
