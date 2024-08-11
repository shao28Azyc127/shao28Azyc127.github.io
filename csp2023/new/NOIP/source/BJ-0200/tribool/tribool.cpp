#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int c,t;
int n,m;
int a[N];
struct node{
    char op;
    int x,y;
}buf[N];
char s[10];
int b[N];
int ans=1000000000;
void dfs(int x){
    if(x==n+1){
       // cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++) b[i]=a[i];
        for(int i=1;i<=m;i++){
            if(buf[i].op=='+'){
                a[buf[i].x]=a[buf[i].y];
            }
            else if(buf[i].op=='-'){
                if(a[buf[i].y]==-1) a[buf[i].x]=-1;
                else if(a[buf[i].y]==1) a[buf[i].x]=2;
                else a[buf[i].x]=1;
          
            }
            else{
                if(buf[i].op=='T') a[buf[i].x]=2;
                else if(buf[i].op=='F') a[buf[i].x]=1;
                else a[buf[i].x]=-1;
            }
        }
        int tmp=0;
        bool flg=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i]) {
                flg=1;
                break;
            }
            if(b[i]==-1) tmp++;
        }
        if(!flg){
            ans=min(ans,tmp);
        }
        for(int i=1;i<=n;i++){
            a[i]=b[i];
        }
        return ;
    }
    //if(a[x]!=0) dfs(x+1);
    
        a[x]=1;
        dfs(x+1);
        a[x]=2;
        dfs(x+1);
        a[x]=-1;
        dfs(x+1);
        a[x]=0;
}
inline void solve1(){
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    ans=1000000000;
    for(int i=1;i<=m;i++){
        scanf("%s",s);
        if(s[0]=='+' || s[0]=='-'){
            buf[i].op=s[0];
            scanf("%d%d",&buf[i].x,&buf[i].y);
        }else{
            buf[i].op=s[0];
            scanf("%d",&buf[i].x);
            // if(buf[i].op=='T') a[buf[i].x]=2;
            // else if(buf[i].op=='F') a[buf[i].x]=1;
            // else a[buf[i].x]=-1;
        }
    }
    dfs(1);
    printf("%d\n",ans);
}
inline void subtask1(){
    while(t--){
        solve1();
    }
}
inline void solve2(){
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    int tt;
    while(m--){
        scanf("%s",s);
        scanf("%d",&tt);
        if(s[0]=='T')
            a[tt]=2;
        else if(s[0]=='F')
            a[tt]=1;
        else a[tt]=-1;
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(a[i]==-1) res++;
    }
    printf("%d\n",res);
}
inline void subtask2(){
    while(t--){
        solve2();
    }
}
vector<pair<int,int> > G[N];
//bool vis[N];
//int mxvis[N];
// void dfs1(int x){
//     //cout<<x<<" ";
//     vis[x]=1;
//     for(auto it:G[x]){
//         if(!vis[it.first]){
//             if(it.second==mxvis[it.first]){
//                 a[it.first]=a[x];
//                 dfs1(it.first);
//             }
                
//         }
//     }
// }
bool vis[N];
bool mxvis[N];
void dfs1(int x,int val){
    vis[x]=1;
    for(auto it:G[x]){
        if(!vis[it.first] && it.second==mxvis[it.first]) {
            a[it.first]=val;
            dfs1(it.first,val);
        }
    }
}
inline void solve3(){
    memset(vis,0,sizeof(vis));
    memset(a,0,sizeof(a));
    memset(mxvis,0,sizeof(mxvis));
    scanf("%d%d",&n,&m);
    //for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=n;i++) G[i].clear();
    int tt,yy;
    for(int i=1;i<=m;i++){
        scanf("%s",s);
        scanf("%d",&tt);
        if(s[0]=='U')
        {
            a[tt]=-1;
            mxvis[tt]=i;
            memset(vis,0,sizeof(vis));
            dfs1(tt,-1);
        }
        else if(s[0]=='+'){
            scanf("%d",&yy);
            //a[tt]=a[yy];
            a[tt]=a[yy];
            mxvis[tt]=i;
            //mxvis[tt]=i;
            G[yy].push_back(make_pair(tt,i));
            memset(vis,0,sizeof(vis));
            //if(a[tt]==0) cout<<"Yes";
            dfs1(tt,a[tt]);
            //G[tt].push_back(yy);
        }
       // cout<<"Yes"<<endl;
    }
    // memset(vis,0,sizeof(vis));
    // for(int i=1;i<=n;i++){
    //     if(!vis[i]) dfs1(i);
    // }
    int res=0;
    for(int i=1;i<=n;i++){
        if(a[i]==-1) res++;
    }
    printf("%d\n",res);
}
inline void subtask3(){
    while(t--){
        solve3();
        //exit(0);
       // cout<<"Yes"<<endl;
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==1 || c==2){
        subtask1();
    }
    else if(c==3 || c==4){
        subtask2();
    }else if(c==5 || c==6){
        subtask3();
    }
    return 0;
}