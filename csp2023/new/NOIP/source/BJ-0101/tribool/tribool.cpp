#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,m;
struct node{
    char opt;
    int i,j;
}hh[100005];
int fa[200005];
//int siz[100005];
int ans[200005];
bool qd[200005];
bool vis[200005];
int finde(int x){
    if(x==fa[x])return x;
    else {
        int hh=finde(fa[x]);
        if(ans[fa[x]]==0x3f3f3f3f)ans[x]=0x3f3f3f3f;
        else ans[x]=ans[fa[x]]+ans[x];
        fa[x]=hh;
        return hh;
    }
}
void add(int x,int y,int opt){
    int a=finde(x),b=finde(y);
    //if(x==7 && y==10)cout<<a<<"asf"<<b<<" "<<opt<<endl;
    if(a==b){
        if(opt==0){
            if(ans[x]%2==ans[y]%2){
                ans[a]=0x3f3f3f3f;
            }
        }
        if(opt==1){
            //if(x==7 && y==10)cout<<ans[x]<<" "<<ans[y]<<"ffghfs"<<endl;
            if(ans[x]%2!=ans[y]%2){
                ans[b]=0x3f3f3f3f;
            }
        }
        return ;
    }
    if(ans[a]==0x3f3f3f3f|| ans[b]==0x3f3f3f3f){
        ans[a]=ans[b]=0x3f3f3f3f;
        fa[b]=a;
        return ;
    }
    if(qd[a]&& qd[b]){
        if(opt==0){
            if(ans[x]%2==ans[y]%2){
                ans[a]=0x3f3f3f3f;
            }
        }
        if(opt==1){
            if(ans[x]%2!=ans[y]%2){
                ans[b]=0x3f3f3f3f;
            }
        }
        fa[b]=a;
        return ;
    }
    if(qd[b])swap(a,b),swap(x,y);
    ans[b]=ans[x]+(opt^1);
    fa[b]=a;
}
int zz[100005];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
            int tot=0;
        //int n,m;
        cin>>n>>m;
        for(int i=1;i<=2*n;i++){
            ans[i]=0;
            qd[i]=0;
            fa[i]=i;
            vis[i]=0;
            zz[i]=i;
        }
        tot=n;
        for(int i=1;i<=m;i++){
            char opt;
            cin>>opt;
            if(opt=='-' || opt=='+'){
                hh[i].opt=opt;
                cin>>hh[i].i>>hh[i].j;
            }
            else{
                hh[i].opt=opt;
                cin>>hh[i].i;
            }
        }
        for(int i=m;i>=1;i--){
            char opt=hh[i].opt;
            int u=hh[i].i,v=hh[i].j;
            if(vis[u])zz[u]=++tot;
            vis[u]=1;
            //if(!zz[v])zz[v]=++tot;
            u=zz[u],v=zz[v];
            //cout<<opt<<" "<<u<<" "<<v<<endl;
            //if(vis[u])continue;
            if(opt=='+' || opt=='-'){
                 //   if(vis[u])continue;
                if(opt=='+')add(u,v,1);
                else add(u,v,0);
            }
            else{
               // if(vis[u])continue;
               //     cout<<opt<<endl;
               if(ans[finde(u)]==0x3f3f3f3f)continue;
                if(opt=='U'){
                     //   cout<<"asg"<<endl;
                    ans[finde(u)]=0x3f3f3f3f;
            //cout<<finde(u)<<"dsfa"<<endl;
                }
                if(opt=='T'){
                    if(!qd[finde(u)]){
                        if(ans[u]%2==1)ans[finde(u)]=1;
                        qd[finde(u)]=1;
                    }
                    else{
                        if(ans[u]%2==1)ans[finde(u)]=0x3f3f3f3f;
                    }
                }
                if(opt=='F'){
                    if(!qd[finde(u)]){
                        if(ans[u]%2==0)ans[finde(u)]=1;
                        qd[finde(u)]=1;
                    }
                    else{
                        if(ans[u]%2==0)ans[finde(u)]=0x3f3f3f3f;
                    }
                }
            }
            /*if(T==5){cout<<i<<endl;
            cout<<opt<<" "<<u<<" "<<v<<endl;
                for(int i=1;i<=n;i++){
                    cout<<ans[i]<<" ";
                }
                cout<<endl;
                for(int i=1;i<=n;i++){
                    cout<<fa[i]<<" ";
                }
                cout<<endl;
                for(int i=1;i<=n;i++){
                    cout<<qd[i]<<" ";
                }
                cout<<endl;
            }*/
            //vis[u]=1;
            //zz[h]
            //vis[v]=0;
        }
        int anser=0;
        for(int i=1;i<=n;i++){
            finde(i);
            //if(T==5)cout<<ans[i]<<" ";
            if(ans[i]==0x3f3f3f3f)anser++;
        }
        //cout<<"\n";
        cout<<anser<<"\n";
    }
}
