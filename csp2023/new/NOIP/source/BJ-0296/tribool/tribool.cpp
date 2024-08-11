#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,x,y,fz[100005],fz2[100005];
char op;
int qf(int x){
    if(x==1)x=2;
    if(x==2)x=1;
    if(x==3)x=3;
    return x;
}
struct node{
    int op,vl;
};
vector<node>e[100005];
bool vis[100005];
void bfs(int no){
    memset(vis,0,sizeof(vis));
    
    queue<int>q;
    q.push(no);
    while(!q.empty()){//if(clock()*1.0/CLOCKS_PER_SEC>0.9)return ;
        
        int now=q.front();
        q.pop();
        for(node i:e[now]){
            //cout<<i.vl<<endl;
            if(vis[i.vl])continue;
            vis[i.vl]=1;
            q.push(i.vl);
            if(i.op==1)
                fz[i.vl]=fz[now];  
            else fz[i.vl]=qf(fz[now]);
            fz2[i.vl]=0;          
        }
    }
    return;
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            fz[i]=0;
            fz2[i]=0;
            e[i].clear();
        }
        for(int i=1;i<=m;i++){
            
            cin>>op;
            if(op=='+'){
                cin>>x>>y;
                if(fz[y]!=0){fz[x]=fz[y];fz2[x]=0;}
                else if(fz2[y]!=0){fz2[x]=fz2[y];fz[x]=0;}
                else {fz2[x]=y;fz[x]=0;}
            }
            else if(op=='-'){
                cin>>x>>y;
                if(fz[y]!=0&&fz[y]!=n+1&&fz[y]!=4){fz[x]=qf(fz[y]);fz2[y]=0;}
                else if(fz2[y]!=0){fz2[x]=-fz2[y];fz[x]=0;}
                else {fz2[x]=-y;fz[x]=0;}
            }
            else{
                cin>>x;
                
                if(op=='T'){fz[x]=1;fz2[x]=0;}
                if(op=='F'){fz[x]=2;fz2[x]=0;}
                if(op=='U'){fz[x]=3;fz2[x]=0;}
            }
        }
        for(int i=1;i<=n;i++){
            if(fz2[i]>0){
                e[fz2[i]].push_back(node{1,i});
            }
            if(fz2[i]<0){
                e[-fz2[i]].push_back(node{-1,i});
            }//cout<<"test"<<fz2[i]<<" "<<i<<endl;
        }
        for(int i=1;i<=n;i++){//cout<<fz[2];
            
            //if(fz2[i]==i);
            if(fz2[i]==-i){
                //cout<<"test"<<fz2[i]<<" "<<i<<endl;
                fz2[i]=0;
                fz[i]=3;
                
            }
            bfs(i);
            //cout<<e[i].size();
        }//cout<<fz[2];
        for(int i=1;i<=n;i++){
            if(fz[i]==3)ans++;
        }
        cout<<ans<<endl;
    }return 0;
}