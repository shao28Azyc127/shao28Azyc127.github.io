#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m,sid;
char val[N],val1[N];
struct node{
    char c;
    int x,y;
}a[N];
int ans;
char no(char x){
    if(x=='T') return 'F';
    if(x=='F') return 'T';
    return 'U';
}
bool check(){
    for(int i=1;i<=n;i++) val1[i]=val[i];
    for(int i=1;i<=m;i++){
        char c=a[i].c;
        int x=a[i].x,y=a[i].y;
        if(c=='+') val1[x]=val1[y];
        else if(c=='-') val1[x]=no(val1[y]);
        else val1[x]=c;
    }
    for(int i=1;i<=n;i++) if(val[i]!=val1[i]) return 0;
    return 1;
}
void dfs(int x,int cnt){
    if(ans<cnt) return;
    if(x==n+1){
        if(check()) ans=min(ans,cnt);
        return;
    }
    val[x]='T',dfs(x+1,cnt);
    val[x]='F',dfs(x+1,cnt);
    val[x]='U',dfs(x+1,cnt+1);
}
int fa[2000010],id[1010][1010],num[2000010];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){//cout<<x<<" "<<y<<"\n";
    x=find(x),y=find(y);
    if(x==y) return;
    fa[x]=y;
}
inline void Do(){
    cin>>n>>m;
    if(sid==3||sid==4){
        for(int i=1;i<=n;i++) val[i]=0;
        for(int i=1;i<=m;i++){
            char c; int x;
            cin>>c>>x;
            val[x]=c;
        }
        ans=0;
        for(int i=1;i<=n;i++){
            if(val[i]=='U') ans++;
        }
        cout<<ans<<"\n";
        return;
    }
    if(sid==1||sid==2){
        for(int i=1;i<=m;i++){
            char c; int x,y;
            cin>>c>>x;
            if(c=='+'||c=='-') cin>>y;
            a[i]={c,x,y};
        }
        ans=n,dfs(1,0);
        cout<<ans<<"\n";
        return;
    }
    int tot=0;
    for(int j=0;j<=m;j++){
        for(int i=1;i<=n;i++) id[j][i]=++tot,fa[tot]=tot,num[tot]=0;
    }
    for(int i=1;i<=n;i++) merge(id[0][i],id[m][i]);
    for(int i=1;i<=m;i++){
        char c; int x,y;
        cin>>c>>x;
        if(c=='+'){
            cin>>y;
            merge(id[i][x],id[i-1][y]);
            for(int j=1;j<=n;j++){
                if(j==x) continue;
                merge(id[i][j],id[i-1][j]);
            }
        }
        else for(int j=1;j<=n;j++){
            merge(id[i][j],id[i-1][j]);
        }
        a[i]={c,x,y};
    }
    for(int i=1;i<=m;i++){
        char c=a[i].c;
        int x=a[i].x;
        if(c=='U') num[find(id[i][x])]=1;
    }
    ans=0;
    for(int i=1;i<=n;i++) if(num[find(id[0][i])]) ans++;
    cout<<ans<<"\n";
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t; cin>>sid>>t;
    while(t--) Do();
    return 0;
}
