#include<bits/stdc++.h>
using namespace std;
struct zt{
    bool op;
    int x;//200011 T 200012 F 200013 U
}ans[100005];
inline zt neg(const zt &x){
    if(x.x<0){
        if(x.x==200011)return zt{0,200012};
        if(x.x==200012)return zt{0,200011};
        if(x.x==200013)return zt{0,200013};
    }
    return zt{x.op^1,x.x};
}
int n,m;
int c,t;
struct bcj{
    int fa[200020];
    int sz[200020];
    inline void init(){
        for(int i=0;i<=200019;i++){
            fa[i]=i;
            sz[i]=1;
        }
    }
    int getfa(int x){
        if(fa[x]==x)return x;
        fa[x]=getfa(fa[x]);
        return fa[x];
    }
    inline void hebing(int a,int b){
        int aa=getfa(a);
        int bb=getfa(b);
//        cout<<"hb"<<a<<" "<<b<<" : "<<aa<<" "<<bb<<endl;
        if(aa==bb)return;
        if(sz[aa]<sz[bb])swap(aa,bb);
        fa[bb]=aa;
        sz[aa]+=sz[bb];
        return;
    }
    inline bool chaxun(int a,int b){
        return getfa(a)==getfa(b);
    }
}k;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)ans[i]=zt{0,i};
        k.init();
        for(int i=1;i<=m;i++){
            char x;
            cin>>x;
            if(x=='+'){
                int a,b;
                cin>>a>>b;
                ans[a]=ans[b];
            }
            if(x=='-'){
                int a,b;
                cin>>a>>b;
                ans[a]=neg(ans[b]);
            }
            if(x=='T'){
                int a;
                cin>>a;
                ans[a]=zt{0,200011};
            }
            if(x=='F'){
                int a;
                cin>>a;
                ans[a]=zt{0,200012};
            }
            if(x=='U'){
                int a;
                cin>>a;
                ans[a]=zt{0,200013};
            }
        }
        for(int i=1;i<=n;i++){
//                cout<<ans[i].op<<" "<<ans[i].x<<endl;
            if(ans[i].x<=200010){
                if(ans[i].op==0){
                    k.hebing(i,ans[i].x);
                    k.hebing(i+100001,ans[i].x+100001);
                }else{
                    k.hebing(i,ans[i].x+100001);
                    k.hebing(i+100001,ans[i].x);
                }
            }else{
                if(ans[i].x==200011){
                    k.hebing(i,200011);
                    k.hebing(i+100001,200012);
                }
                if(ans[i].x==200012){
                    k.hebing(i,200012);
                    k.hebing(i+100001,200011);
                }
                if(ans[i].x==200013){
                    k.hebing(i,200013);
                    k.hebing(i+100001,200013);
                }
            }
            if(k.chaxun(i,i+100001))k.hebing(i,200013);
        }
//        return 0;
        cout<<(k.sz[k.getfa(200013)]-1)/2<<endl;
    }
    return 0;
}
