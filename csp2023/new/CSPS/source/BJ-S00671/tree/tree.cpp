#include <bits/stdc++.h>
#define MAXN 100000
#define ll long long
#define db double
#define P 1000000007

using namespace std;

int n;
ll a[MAXN+5];
ll b[MAXN+5];
ll c[MAXN+5];
ll times[MAXN+5];
int vis[MAXN+5];
ll len[MAXN+5];
ll ans=-1;
int ID;
int okcnt=0;
vector<int> e[MAXN+5];
int kind=2;

int main(){

    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        if(u!=i||v!=i+1) kind=0;
    }
    if(kind==1){
        for(int i=1;i<=n;i++){
            times[i]=a[i]/b[i];
            if(a[i]%b[i]!=0) times[i]++;
        }
        vis[1]=1;
        for(int i=1;i<=n;i++){
            ll mx=-1;
            int id;
            for(int j=1;j<=n;j++){
                if(vis[j]!=1) continue;
                if(mx<=times[j]){mx=times[j];id=j;}
            }
            vis[id]=-1;
            if(ans<times[id]+i-1) {ans=times[id]+i-1;ID=id;}
            for(int j=0;j<e[id].size();j++){
                if(vis[e[id][j]]==0) vis[e[id][j]]=1;
            }
        }
        cout<<ans<<endl;
    }
    if(kind==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                len[j]+=max(b[j]+c[j]*i,(ll)1);
                if(len[j]>a[j]&&vis[j]==0) {vis[j]=1;okcnt++;}
            }

        }
        ans=n;
        while(okcnt<n){
            for(int i=1;i<=n;i++){
                len[i]+=max(b[i]+c[i]*ans,(ll)1);
                if(len[i]>a[i]&&vis[i]==0) vis[i]=1;okcnt++;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
