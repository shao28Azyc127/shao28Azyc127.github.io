#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
//#define int long long
using namespace std;
const int N=1e5+5,T=1e6,F=2e6,U=3e6,X=1e5;
int c,t,n,m,x,y,f[2*N],ans;
char v;
bool flag[N];
struct TT {
    int num,b;
}a[N];
int gf(int x){
    if(f[x]==x) return f[x];
    return f[x]=gf(f[x]);
}
void add(int x,int y){
    int fx=gf(x),fy=gf(y);
    f[fx]=fy;
}
bool ck(int x,int y){
    int fx=gf(x),fy=gf(y);
    if(fx==fy) return true;
    return false;
}
vector<int> good[N];
void dfs(int x){
    if(flag[x]) return;
    flag[x]=true;
    for(int i=0;i<good[x].size();i++){
        dfs(good[x][i]);
    }
}
signed main() {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            a[i]= (TT){i,1ll} ;
            f[i]=i;
            f[ i+X ]=i+X;
        }
        for(int i=1;i<=m;i++){
            cin>>v;
            if(v=='T'){
                cin>>x;
                a[x].num=T;
                a[x].b=0;
            }
            if(v=='F'){
                cin>>x;
                a[x].num=F;
                a[x].b=0;
            }
            if(v=='U'){
                cin>>x;
                a[x].num=U;
                a[x].b=0;
            }
            if(v=='+'){
                cin>>x>>y;
                a[x]=a[y];
            }
            if(v=='-'){
                cin>>x>>y;
                if(a[y].b==0){
                    if(a[y].num==T)
                        a[x].num=F;
                    if(a[y].num==F)
                        a[x].num=T;
                    if(a[y].num==U)
                        a[x].num=U;
                    a[x].b=0;
                }
                else{
                    a[x].num=a[y].num;
                    a[x].b=(-1)*a[y].b;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i].b==-1){
                add(i,a[i].num+X);
                add(i+X,a[i].num);
            }
            if(a[i].b==1){
                add(i,a[i].num);
                add(i+X,a[i].num+X);
            }
            if(a[i].b!=0){
                good[i].push_back(a[i].num);
                good[a[i].num].push_back(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(!flag[i]&&(a[i].num==U||ck(i,i+X))){
                dfs(i);
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            if(flag[i]) ans++;
        }
        cout<<ans<<endl;
        memset(flag,0,sizeof(flag));
        for(int i=1;i<=n;i++)
            good[i].clear();

    }
    return 0;
}
