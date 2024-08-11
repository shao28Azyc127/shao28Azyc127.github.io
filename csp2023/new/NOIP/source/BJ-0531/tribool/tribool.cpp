#include <iostream>
#include <set>
using namespace std;
const int N=100010;
set<int>st[N<<1];
int c,T,n,m,a[N],fa[N<<1],vis[N<<1],cnt[N<<1],viss[N<<1],ans[N],anss;//a[i]=1->T =2->U =3->F
int fd1(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=fd1(fa[x]);
}
int fd(int x,int flag){
    if(fa[x]==x){
        return x;
    }
    int fa1=fd(fa[x],flag);
    st[fa[x]].erase(x);
    if(flag==0){
        st[fa1].insert(x);
    }else{
        st[fa1].insert(-x);
    }
    return fa[x]=fa1;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d %d",&c,&T);
    while(T--){
        anss=0;
        scanf("%d %d",&n,&m);
        if(c==3||c==4||c==5||c==6){
            char op;
            int x,y;
            while(m--){
                cin>>op;
                if(op=='U'){
                    cin>>x;
                    a[x]=2;
                }else if(op=='T'){
                    cin>>x;
                    a[x]=1;
                }else if(op=='F'){
                    cin>>x;
                    a[x]=3;
                }else if(op=='+'){
                    cin>>x>>y;
                    fa[fd1(x)]=fd1(y);
                }
            }
            for(int i=1;i<=n;i++){
                fd1(i);
            }
            for(int i=1;i<=n;i++){
                if(a[i]==2){
                    vis[fd1(i)]=1;
                }
            }
            for(int i=1;i<=n;i++){
                if(vis[fd1(i)]){
                    anss++;
                }
            }
            cout<<anss<<endl;
        }else{
            anss=0;
            for(int i=1;i<=n;i++){
                a[i]=0;
            }
            for(int i=1;i<=n;i++){
                st[i].clear();
                st[i+N].clear();
                a[i]=0;
                a[i+N]=0;
                fa[i]=i;
                fa[i+N]=i+N;
                viss[i]=1;
                viss[i+N]=0;
                st[i].insert(i);
                st[i+N].insert(i+N);
            }
                while(m--){
                char op;
                int x,y;
                cin>>op;
                if(op=='U'){
                    cin>>x;
                    a[x+N]=2;
                    a[x]=2;
                }else if(op=='T'){
                    cin>>x;
                    a[x+N]=1;
                    a[x]=3;
                }else if(op=='F'){
                    cin>>x;
                    a[x+N]=3;
                    a[x]=1;
                }else if(op=='+'){
                    cin>>x>>y;
                    int fa1=fd(x+N,viss[x+N]^viss[y+N]),fa2=fd(y+N,0);
                    fa[fa1]=fa2;
                    st[fa2].insert(x+N);
                    viss[x+N]=viss[y+N];
                    vis[x+N]=1;
                    vis[y+N]=1;
                }else if(op=='-'){
                    cin>>x>>y;
                    int fa1=fd(x+N,viss[x+N]^viss[y]),fa2=fd(y,0);
                    fa[fa1]=fa2;
                    st[fa2].insert(x+N);
                    viss[x+N]=vis[y];
                    vis[x+N]=1;
                    vis[y]=1;
                }
            }
            for(int i=1;i<=n;i++){
                if(!vis[i]||!vis[i+N]){
                    continue;
                }
                fa[fd(i+N,viss[i]^viss[i+N])]=fd(i,0);
                viss[i+n]=viss[i];
            }
            for(int i=1;i<=n;i++){
                int fa2=fd(i+N,0);
                if(!cnt[fa2]){
                    if(*lower_bound(st[fa2].begin(),st[fa2].end(),i)==i){
                        anss+=st[fa2].size();
                        cnt[fa2]=1;
                    }
                }
                if(!cnt[fa2]&&a[i]==2){
                    anss+=st[fa2].size();
                    cnt[fa2]=1;
                }
            }
            cout<<anss<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
