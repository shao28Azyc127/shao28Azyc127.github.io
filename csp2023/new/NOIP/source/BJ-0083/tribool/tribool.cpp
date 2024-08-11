#include<bits/stdc++.h>
using namespace std;
const int NR=2e5+10;
int c,T,n,m,from[NR],val[NR],ans[NR];

int fa[NR],size[NR];
void init(){
    for(int i=1;i<=2*n;i++)
        fa[i]=i,size[i]=1,ans[i]=0;
    for(int i=1;i<=n;i++)
        from[i]=from[i+n]=i,val[i]=1,val[i+n]=-1;
}
int get(int x){
    if(fa[x]==x)return x;
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    x=get(x);y=get(y);
    if(x==y)return;
    fa[x]=y;size[y]+=size[x];
}

void solve(){
    scanf(" %d %d",&n,&m);init();
    for(int i=1;i<=m;i++){
        char opt;scanf(" %c",&opt);
        if(opt=='-'){
            int x,y;scanf(" %d%d",&x,&y);
            from[x]=from[y];val[x]=-val[y];
        }
        if(opt=='+'){
            int x,y;scanf(" %d%d",&x,&y);
            from[x]=from[y];val[x]=val[y];
        }
        if(opt=='T'){
            int x;scanf(" %d",&x);
            from[x]=0;val[x]=1;
        }
        if(opt=='U'){
            int x;scanf(" %d",&x);
            from[x]=0;val[x]=0;
        }
        if(opt=='F'){
            int x;scanf(" %d",&x);
            from[x]=0;val[x]=-1;
        }
    }
    // for(int i=1;i<=n;i++)printf("%d %d\n",from[i],val[i]);
    for(int i=1;i<=n;i++)
        if(from[i]){
            if(val[i]==1)merge(i,from[i]),merge(i+n,from[i]+n);
            else merge(i,from[i]+n),merge(i+n,from[i]);
        }
    for(int i=1;i<=n;i++){
        int x=get(i),y=get(i+n);
        if(x==y)ans[x]=1;
        if(!from[i]&&!val[i])ans[x]=ans[y]=1;
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=ans[get(i)];
        // if(ans[get(i)])printf("----%d\n",i);
        // printf("i:%d from:%d\n",i,get(i));
    }
    cout<<sum<<endl;
}

signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>T;
    while(T--)solve();
    return 0;
}