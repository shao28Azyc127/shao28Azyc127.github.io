#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=2e5+7;
int fun(int a,int op){
    if(a==2)return a;
    return (op==1)?a:(!a);
}
namespace s5{
    int li[N],n,m,f[N];
    int find(int a){
        if(a==f[a])return a;
        return f[a]=find(f[a]);
    }
    void U(int a,int b){
        a=find(a);b=find(b);
        f[a]=b;
    }
    int fan(int u){
        if(u>2*n){
            if(u==2*n+3)return u;
            return (u==2*n+1)?2*n+2:2*n+1;
        }
        if(u>n)return u-n;
        return u+n;
    }
    signed work(){
        memset(f,0,sizeof f);
        memset(li,0,sizeof li);
        cin>>n>>m;
        rep(i,2*n+3)f[i]=i,li[i]=i;
        while(m--){
            char oP[2],op;int x,y;
            scanf("%s%d",oP,&x);
            op=oP[0];
            if(op=='+')scanf("%d",&y),li[x+n]=fan(li[y]),li[x]=li[y];
            else if(op=='-')scanf("%d",&y),li[x]=fan(li[y]),li[x+n]=li[y];
            else if(op=='T')li[x]=2*n+1,li[x+n]=2*n+2;
            else if(op=='F')li[x]=2*n+2,li[x+n]=2*n+1;
            else li[x]=2*n+3,li[x+n]=2*n+3;
        }
        rep(i,n)U(i,li[i]),U(i+n,fan(li[i]));
        int tk=0;
        rep(i,n)if(find(i)==find(i+n)&&find(i)!=find(2*n+3))U(i,2*n+3);
        int ans=0;//cout<<tk<<'\n';
        rep(i,n)if(find(i)==find(2*n+3))++ans;
        cout<<ans<<'\n';
        return 0;
    }
    signed main(){
        int t;cin>>t;
        while(t--)work();
        return 0;
    }
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c;
    cin>>c;
    s5::main();
    return 0;
}
