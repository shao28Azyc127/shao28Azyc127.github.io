#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int vis3[N],vis2[N],vis[N];
int ans[N],num[N],n,m,c;
vector<int>vc[N],vc2[N];
int ru[N],flag[N];

int dfs(int u){
    int res=1;vis[u]=1;
    for(int i=0;i<vc[u].size();i++){
        if(!vis[vc[u][i]])res+=dfs(vc[u][i]);
    }return res;
}
int cnt(int u){
    int res=0;vis3[u]=1;
    for(int i=0;i<vc[u].size();i++){
        //cout<<"!!!"<<vis3[vc[u][i]]<<endl;
        if(vis2[vc[u][i]])continue;
        res+=num[vc[u][i]];
        if(!vis3[vc[u][i]])res+=cnt(vc[u][i]);
    }
    //cout<<"!!"<<u<<"->"<<res<<endl;int ans[N],num[N],n,m,c;
    return res;
}

char top[N];int x[N],y[N],ans2,nn[N],ed[N];
bool check(){
    for(int i=1;i<=n;i++)ed[i]=nn[i];
    for(int i=1;i<=m;i++){
        if(top[i]=='+'){
            ed[x[i]]=ed[y[i]];
        }else if(top[i]=='-')ed[x[i]]=2-ed[y[i]];
        else if(top[i]=='T')ed[x[i]]=0;
        else if(top[i]=='F')ed[x[i]]=2;
        else ed[x[i]]=1;
    }
    for(int i=1;i<=n;i++)if(ed[i]!=nn[i])return false;
    return true;
}int ct(){
    int res=0;for(int i=1;i<=n;i++)res+=(nn[i]==1);return res;
}
void fd(int lst){
    if(lst==0){
        if(check())ans2=min(ans2,ct());
        return;
    }
    nn[lst]=0;fd(lst-1);
    nn[lst]=1;fd(lst-1);
    nn[lst]=2;fd(lst-1);
}
void calc(){
    for(int i=1;i<=m;i++){cin>>top[i]>>x[i];if(top[i]=='+'||top[i]=='-')cin>>y[i];}
    ans2=n;
    fd(n);cout<<ans2<<endl;
}

void test(){
    cin>>n>>m;
    if(c<=2){
        calc();return;
    }
    for(int i=1;i<=n+2;i++)ans[i]=i,num[i]=0,flag[i]=0;
    char op;int x,y,u,v,w;
    for(int i=1;i<=m;i++){
        cin>>op>>x;
        //cout<<op<<","<<x<<endl;
        if(op=='+'){
            cin>>y;
            if(ans[y]==x){
                if(num[y]&1)flag[x]=1;
            }
            else{
                ans[x]=ans[y],num[x]=num[y];flag[x]=0;
            }
            //ans[x]=y;num[x]=0;
        }else if(op=='-'){
            cin>>y;
            if(ans[y]==x){
                if(num[y]^1)flag[x]=1;
            }
            else{
                ans[x]=ans[y],num[x]=num[y]+1 ;flag[x]=0;
            }
            //ans[x]=y;num[x]=1;
        }else if(op=='T'||op=='F'){
            flag[x]=0;
            ans[x]=n+1;num[x]=0;
            //cout<<"!!!!!!!!!!!"<<endl;
        }else if(op=='U'){
            flag[x]=1;
            ans[x]=n+2;num[x]=0;
        }
    }
    for(int i=1;i<=n+2;i++)vc[i].clear(),vc2[i].clear(),vis3[i]=vis2[i]=vis[i]=0,ru[i]=0;
    for(int i=1;i<=n;i++){
        vc[ans[i]].push_back(i);ru[ans[i]]++;vc2[i].push_back(ans[i]);
        //cout<<i<<"  ---"<<num[i]<<"-->>>   "<<ans[i]<<endl;
    }
    int ans=dfs(n+2)-1;
    queue<int>que;
    for(int i=1;i<=n;i++){
        if(ru[i]==0)vis2[i]=1,que.push(i);
    }
    while(que.size()){
        int x=que.front();que.pop();
        for(int i=0;i<vc2[x].size();i++){
            ru[vc2[x][i]]--;
            if(ru[vc2[x][i]]==0)vis2[vc2[x][i]]=1,que.push(vc2[x][i]);
        }
    }
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        if(flag[i]){
            if(vis[i])continue;
            //cout<<"\t"<<i<<endl;
            ans+=dfs(i);
        }
        if(!vis[i]&&!vis3[i]){
            int t=cnt(i);
            //cout<<i<<": "<<t<<endl;
            if(t&1)ans+=dfs(i);
        }
    }
    //cout<<"\nans=";
    cout<<ans<<endl;
}

signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int t;cin>>c>>t;while(t--)
        test();
    return 0;
}
