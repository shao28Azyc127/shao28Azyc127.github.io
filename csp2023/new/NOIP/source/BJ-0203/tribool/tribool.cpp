#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
const int N=2e5+5;
int n,m,now[N],vis[N];
char s[N],en[N];
int fa[N];
int find(int x) {
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void init() {
    rep(i,1,n*2) fa[i]=i;
    rep(i,1,n) now[i]=i,s[i]=0,en[i]=0,vis[i]=0;
}
char fe(char c) {
    if(c=='F') return 'T';
    if(c=='T') return 'F';
    return 'U';
}
int get(int x) {
    if(x>n) return x-n;
    return x;
}
int dfs(int x) {
    if(en[x]!=0) return en[x];
    if(vis[x]) return 0;
    vis[x]=1;
    en[x]=dfs(get(now[x]));
    return en[x];
}
int fan(int x) {
    if(x>n) return x-n;
    else return x+n;
}
int c,t;
int main() {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--) {
        int ans=0;
        cin>>n>>m;
        init();
        rep(i,1,m) {
            char op;
            int x,y;
            cin>>op;
            if(op=='T'||op=='F'||op=='U') {
                cin>>x;
                s[x]=op;
                now[x]=0;
            } else {
                cin>>x>>y;
                if(op=='+') {
                    if(now[y]!=0) {
                        now[x]=now[y];
                        s[x]=0;
                    } else {
                        now[x]=0;
                        s[x]=s[y];
                    }
                } else {
                    if(now[y]!=0) {
                        if(now[y]<=n) {
                            now[x]=now[y]+n;
                        } else {
                            now[x]=now[y]-n;
                        }
                        s[x]=0;
                    } else {
                        now[x]=0;
                        s[x]=fe(s[y]);
                    }
                }
            }
        }
        rep(i,1,n) if(!s[i]) {
            fa[find(i)]=find(now[i]);
            fa[find(fan(i))]=find(fan(now[i]));
        } else en[i]=s[i];
        rep(i,1,n) if(find(i)==find(i+n)) en[i]='U';
        //cout<<endl;
        //rep(i,1,n) cout<<en[i]<<' '<<now[i]<<endl;
        rep(i,1,n) if(!en[i]) en[i]=dfs(get(now[i]));
        rep(i,1,n) if(en[i]=='U') ans++;
        cout<<ans<<endl;
    }
    return 0;
}

