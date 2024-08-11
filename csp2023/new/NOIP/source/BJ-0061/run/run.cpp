#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,m,k,d;
long long f[1005][1005];
map<long long,int> id;
long long dots[300005];
int cnt=0;
vector<int> star[300005];
vector<long long> jl[300005];
long long l[100005];
long long r[100005];
long long v[100005];
long long rnb[300005];
//int st[300005];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>t;
    if(c>=17&&c<=18){
        while(t--){
            cin>>n>>m>>k>>d;
            long long ans=0;
            for(int i=1;i<=m;i++){
                long long x,y,v;
                cin>>x>>y>>v;
                if(y<=k)ans+=max(0ll,v-y*d);
            }
            cout<<ans<<endl;
        }
    }
    if(c<=11){
        while(t--){
            cin>>n>>m>>k>>d;
            id.clear();
            cnt=0;
            memset(rnb,0,sizeof(rnb));
            for(int i=1;i<=m;i++){
                long long x,y,vv;
                cin>>x>>y>>vv;
                r[i]=x;
                l[i]=x-y+1;
                v[i]=vv;
                dots[++cnt]=r[i];
                dots[++cnt]=l[i];
            }
            sort(dots+1,dots+1+cnt);
            int cntk=0;
            for(int i=1;i<=cnt;i++){
                if(i==1||dots[i]!=dots[i-1]){
                    id[dots[i]]=++cntk;
                    rnb[cntk]=dots[i];
                }
            }
            for(int i=1;i<=cntk;i++){
                star[i].clear();
                jl[i].clear();
            }
            for(int i=1;i<=n;i++){
                r[i]=id[r[i]];
                l[i]=id[l[i]];
                star[r[i]].push_back(l[i]);
                jl[r[i]].push_back(v[i]);
            }
            memset(f,-39999,sizeof(f));
            for(int i=1;i<=cntk+1;i++)f[i][i-1]=0;
            for(int i=1;i<=cntk+1;i++){
                for(int j=1;j<=cntk;j++){
                    if(i==j+1){
                        for(int x=1;x<=j;x++){
                            f[i][j]=max(f[i][j],f[x][j-1]);
                        }
                    }
                    if(i>j)continue;
                    if(rnb[j]-rnb[i]+1>k){
                        f[i][j]=-4e18;
                        continue;
                    }
                    if(i==j){
                        f[i][j]=max(f[i][j],f[i][i-1]-d);
                    }else f[i][j]=max(f[i][j],f[i][j-1]-d*(rnb[j]-rnb[j-1]));
                    for(int x=0;x<star[j].size();x++){
                        if(i<=star[j][x]){
                            f[i][j]+=jl[j][x];
                        }
                    }
                }
            }
//            for(int i=1;i<=n+1;i++){
//                for(int j=1;j<=n;j++){
//                    cout<<i<<" "<<j<<"   "<<f[i][j]<<endl;
//                }
//            }
            long long ans=0;
            for(int i=1;i<=cntk+1;i++){
                ans=max(ans,f[i][cntk]);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
