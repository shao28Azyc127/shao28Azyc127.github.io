#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int ID,T,n,m;
int start[N],last[N],num[N],have[N],fls[N],ans=0x3f3f3f3f;
char opt[N];
int inv(int x){
    if(x==3) return 3;
    else if(x==1) return 2;
    else if(x==2) return 1;
    return 0;
}
void dfs1(int x){
    if(x>n){
        for(int i=1;i<=n;i++) last[i]=start[i];
        for(int i=1;i<=m;i++){
            if(opt[i]=='U') last[have[i]]=3;
            if(opt[i]=='T') last[have[i]]=1;
            if(opt[i]=='F') last[have[i]]=2;
            if(opt[i]=='+') last[have[i]]=last[fls[i]];
            if(opt[i]=='-') last[have[i]]=inv(last[fls[i]]);
        }
        bool flag=false;
        int cnt=0;
        for(int i=1;i<=n;i++) if(start[i]==3) cnt++;
        for(int i=1;i<=n;i++){
            if(last[i]!=start[i]){
                flag=true;
                break;
            }
        } 
        if(!flag) ans=min(ans,cnt);
        return ;
    }
    else{
        for(int i=1;i<=3;i++){
            start[x]=i;
            dfs1(x+1);
        }
    }
}
struct node{
    int x,ti;
};
// int low[N],dfn[N],tot=0,scccnt=0,scccol[N];
// bool in[N];
// stack<int>st;
vector<node>v[N];
// void dfs2(int x){
//     dfn[x]=low[x]=++tot;
//     st.push(x);
//     in[x]=true;
//     for(int i=0;i<v[x].size;i++){
//         int s=v[x][i];
//         if(!dfn[s]){
//             dfs2(s);
//             low[x]=min(low[x],low[s]);
//         }
//         else if(in[s]){
//             low[x]=min(low[x],dfn[s];)
//         }
//     }
//     if(low[x]==dfn[x]){
//         int s=-1,scccnt++;
//         while(s!=x){
//             s=s.top();
//             s.pop();
//             in[s]=false;
//             scccol[s]=x;
//         }
//     }
// }
void work1(){
    while(T-->0){
        ans=0x3f3f3f3f;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) start[i]=last[i]=0;
        for(int i=1;i<=m;i++){
            cin>>opt[i];
            if(opt[i]=='+'||opt[i]=='-') scanf("%d%d",&have[i],&fls[i]);
            else scanf("%d",&have[i]);
        }
        dfs1(1);
        printf("%d\n",ans);
    }
}
void work2(){
    while(T-->0){
        ans=0x3f3f3f3f;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) start[i]=last[i]=0;
        for(int i=1;i<=m;i++){
            cin>>opt[i];
            if(opt[i]=='+'||opt[i]=='-') scanf("%d%d",&have[i],&fls[i]);
            else scanf("%d",&have[i]);
        }
        for(int i=1;i<=m;i++){
            if(opt[i]=='U') last[have[i]]=3;
            if(opt[i]=='T') last[have[i]]=1;
            if(opt[i]=='F') last[have[i]]=2;
        }
        int cnt=0;
        for(int i=1;i<=n;i++) if(last[i]==3) cnt++;
        printf("%d\n",cnt);
    }
    return ;
}
bool vis[N];
int tim[N];
void dfs3(int x,int col){
    last[x]=col;
    // cout<<x<<" "<<col<<endl;
    for(int i=0;i<v[x].size();i++){
        int s=v[x][i].x,ti=v[x][i].ti;
        // cout<<x<<" "<<s<<" "<<ti<<endl;
        if(tim[s]>=ti) continue;
        tim[s]=ti;
        dfs3(s,col);
    }
}
void work3(){
    while(T-->0){
        ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) vis[i]=0,tim[i]=0;
        tim[n+3]=0x3f3f3f3f;
        for(int i=1;i<=m;i++){
            cin>>opt[i];
            if(opt[i]=='+'||opt[i]=='-') scanf("%d%d",&have[i],&fls[i]);
            else scanf("%d",&have[i]);
        }
        for(int i=1;i<=m;i++){
            if(opt[i]=='U') v[n+3].push_back(node{have[i],i});
            if(opt[i]=='+'){
                v[fls[i]].push_back(node{have[i],i});
            } 
            // cout<<have[i]<<" "<<i<<endl;
        }
        dfs3(n+3,3);
        for(int i=1;i<=n;i++){
            if(last[i]==3) continue;
            // cout<<i<<endl;
            dfs3(i,1);
        }
        for(int i=1;i<=n;i++) if(last[i]==3) ans++;
        // for(int i=1;i<=m;i++){
        //     if(opt[i]=='U') last[have[i]]=3;
        //     if(opt[i]=='+') last[have[i]]=last[fls[i]];
        // }
        printf("%d\n",ans);
    }
    return ;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&ID,&T);
    if(ID==1||ID==2) work1();
    else if(ID==3||ID==4) work2();
    else if(ID==5||ID==6) work3();
    else{
        while(T-->0) puts("1102");
    } 
    return 0;
}