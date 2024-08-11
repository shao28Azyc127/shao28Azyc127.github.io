#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MXN=1e3+10,MXM=1e3+10;
struct tz{
    int y;
    LL v;
    bool operator <(const tz &r)const{
        return y<r.y;
    }
};
int c,T,n,m,k;
LL f[MXN][MXN],d;
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>T;
    while(T--){
        memset(f,0,sizeof(f));
        cin>>n>>m>>k>>d;
        vector<vector<tz>> t(n+1);
        for(int i=1,x,y,v;i<=m;i++){
            cin>>x>>y>>v;
            t[x].push_back((tz){y,v});
        }
        for(int i=1;i<=n;i++){
            sort(t[i].begin(),t[i].end());
            LL sum=0;
            for(int j=0,lk=0;j<=min(i,k);j++){
                if(j>0){
                    f[i][j]=f[i-1][j-1]-d;
                }else{
                    for(int l=0;l<=min(i-1,k);l++){
                        f[i][j]=max(f[i][j],f[i-1][l]);
                    }
                }
                while(lk<t[i].size()&&t[i][lk].y<=j){
                    sum+=t[i][lk].v;
                    lk++;
                }
                f[i][j]+=sum;
                //cout<<f[i][j]<<' ';
            }
            //cout<<'\n';
        }
        LL ans=f[n][0];
        for(int i=1;i<=min(n,k);i++){
            ans=max(ans,f[n][i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
