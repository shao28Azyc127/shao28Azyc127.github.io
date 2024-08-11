#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
using namespace std;
typedef pair<int,int> Pair;
template<class T>inline T qmax(const T &x,const T &y){return x>y?x:y;}
template<class T>inline T qmin(const T &x,const T &y){return x<y?x:y;}
inline void qread(){}template<class T1,class ...T2>
inline void qread(T1 &a,T2 &...b){
    register T1 x=0;register bool f=false;char ch=getchar();
    while(ch<'0') f|=(ch=='-'),ch=getchar();
    while(ch>='0') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    x=(f?-x:x);a=x;qread(b...);
}const int MAXN=3e5+7,MAXM=6e4+7;
int c,T,n,m,f[MAXN],sz[MAXN],ans=0;string op;vector<int>a[MAXN],e[MAXN];
bool g[MAXN],flag;int cnt,col[MAXN];
// namespace _1{
//     int a[17];
//     int qpow(int b,int p){
//         int res=1;
//         while(p){
//             if(p&1) res=res*b;
//             p>>=1;b=b*b;
//         }return res;
//     }void solve(){
//         while(T--){
//             cin>>n>>m;
//             for(i=0;i<)
//         }
//     }
// }
void dfs(int u,int fa){
    for(auto v:e[u]){
        if(g[v]) flag=true,g[u]=true;
        if(v==fa) continue;
        if(col[v]==col[u]) flag=true,g[u]=true;
        if(!col[v]) col[v]=-col[u],cnt+=sz[v],dfs(v,u);
    }
}int main(){
    fre("tribool");
    // fre("tribool//tribool4");
    // fre("1");
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);int i,j;
    cin>>c>>T;
    while(T--){
        cin>>n>>m;ans=0;
        for(i=1;i<=n*2+3;i++) f[i]=i,e[i].clear(),a[i].clear(),sz[i]=0,col[i]=0,g[i]=false;
        while(m--){
            cin>>op;
            if(op[0]=='+'){
                cin>>i>>j;
                f[i]=f[j];
            }if(op[0]=='-'){
                cin>>i>>j;
                if(f[j]<=n) f[i]=f[j]+n;
                else if(f[j]<=n*2) f[i]=f[j]-n;
                else if(f[j]==n*2+1) f[i]=n*2+2;
                else if(f[j]==n*2+2) f[i]=n*2+1;
                else if(f[j]==n*2+3) f[i]=f[j];
            }if(op[0]=='T'){
                cin>>i;f[i]=n*2+1;
            }if(op[0]=='F'){
                cin>>i;f[i]=n*2+2;
            }if(op[0]=='U'){
                cin>>i;f[i]=n*2+3;
            }
        }for(i=1;i<=n;i++) sz[f[i]]++,a[f[i]].emplace_back(i);
        // for(i=1;i<=n;i++) cout<<f[i]<<" ";cout<<endl;
        for(i=1;i<=n*2+3;i++){
            for(auto j:a[i]){
                int t;if(j<=n) t=j+n;else if(j<=2*n) t=j-n;
                if(j==n*2+1) t=n*2+2;if(j==n*2+2) t=n*2+1;
                e[i].emplace_back(t),e[t].emplace_back(i);
            }j=i;
            int t;if(j<=n) t=j+n;else if(j<=2*n) t=j-n;
            if(j==n*2+1) t=n*2+2;if(j==n*2+2) t=n*2+1;if(j==n*2+3) t=i;
            e[i].emplace_back(t);e[t].emplace_back(i);
        }e[n*2+1].emplace_back(n*2+2);e[n*2+2].emplace_back(n*2+1);
        // for(i=1;i<=n*2+3;i++) for(auto j:e[i]) cout<<i<<" "<<j<<endl;
        for(i=1;i<=n*2+3;i++){
            if(!col[i]){
                flag=false,cnt=sz[i],col[i]=1,dfs(i,0);
                if(flag) ans+=cnt;
                // cout<<ans<<" "<<cnt<<endl;
            }
        }cout<<ans<<endl;
    }
    return 0;
}