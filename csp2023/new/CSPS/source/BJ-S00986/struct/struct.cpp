#include <bits/stdc++.h>
#define il inline
#define pii pair<string,string>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=105;
int q,n,m;ll cur;
struct node{
    string t[N],id[N];int k;ll mx,siz;
    il node(){for(int i=1;i<N;++i) t[i]=id[i]="";k=0,mx=siz=0ll;}
}a[N];
struct A{
    string t,id;ll st,ed;
    il A(){t=id="",st=ed=0ll;}
}b[N];
map<string,int> mp,mp1;//type,name
il ll getmx(string s){
    if(s=="byte") return 1ll;
    else if(s=="short") return 2ll;
    else if(s=="int") return 4ll;
    else if(s=="long") return 8ll;
    else return a[mp[s]].mx;
}
il ll getsiz(string s){
    if(s=="byte") return 1ll;
    else if(s=="short") return 2ll;
    else if(s=="int") return 4ll;
    else if(s=="long") return 8ll;
    else return a[mp[s]].siz;
}
il int get(int id,string s){
    for(int i=1;i<=a[id].k;++i) if(a[id].id[i]==s) return i;
}
il ll nxt(ll x,ll y){
    if(x%y) return (x/y+1ll)*y;
    return x;
}
il int ck(string s){
    if(s=="byte") return 1;
    else if(s=="short") return 1;
    else if(s=="int") return 1;
    else if(s=="long") return 1;
    return 0;
}
vector<string> f;
int opt,k;string s,t,r,tt;
string dfs(string t,string id,ll l,ll r,ll x){
    if(ck(t)){
        if(x>=l && x<=r) return id;
        else return "ERR";
    }
    int u=mp[t];ll cur=l,y,z;
    for(int i=1;i<=a[u].k;++i){
        y=getsiz(a[u].t[i]),z=getmx(a[u].t[i]);
        if(nxt(cur,z)+y>x){
            string s=dfs(a[u].t[i],a[u].id[i],nxt(cur,z),nxt(cur,z)+y-1ll,x);
            if(s=="ERR") return s;
            else return id+"."+s;
        }
        cur=nxt(cur,z)+y;
    }
    return "ERR";
}
ll x,y,z,mx,ans;
int id,u,v,w;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&opt);
        if(opt==1){
            cin>>s>>k;mp[s]=++n,a[n].k=k;
            x=mx=0ll;
            for(int i=1;i<=k;++i){
                cin>>a[n].t[i]>>a[n].id[i];
                y=getmx(a[n].t[i]),mx=max(mx,y);
                x=nxt(x,y)+getsiz(a[n].t[i]);
            }
            if(x%mx) x=(x/mx+1ll)*mx;
            a[n].siz=x,a[n].mx=mx;
            printf("%lld %lld\n",a[n].siz,a[n].mx);
        }
        else if(opt==2){
            cin>>s>>t;b[++m].t=s,b[m].id=t;
            x=getmx(s);
            if(cur%x) cur=(cur/x+1ll)*x;
            printf("%lld\n",cur);
            b[m].st=cur,b[m].ed=cur+getsiz(s)-1ll,cur+=getsiz(s);
        }
        else if(opt==3){
            cin>>s;int len=s.size();
            u=-1,f.clear();
            for(int i=0;i<len;++i){
                if(s[i]=='.'){f.push_back(s.substr(u+1,i-u-1)),u=i;}
            }
            f.push_back(s.substr(u+1,len-1-u));
            t=r="",ans=0ll;
            for(int i=1;i<=m;++i){
                if(b[i].id==f[0]) {t=b[i].t,r=b[i].id;break;}
                else ans=b[i].ed;
            }
            tt=t;
            for(int i=1;i<f.size();++i){
                string p=t;
                for(int j=1;j<=a[mp[t]].k;++j) if(a[mp[t]].id[j]==f[i]){u=j;break;}
                for(int j=1;j<u;++j)
                    x=getmx(a[mp[t]].t[j]),ans=nxt(ans,x)+getsiz(a[mp[t]].t[j]);
                t=a[mp[p]].t[u],r=a[mp[p]].id[u];
            }
            ans=nxt(ans,getmx(t));
            printf("%lld\n",ans);
        }
        else{
            scanf("%lld",&x);
            int p=0;
            for(int i=1;i<=m;++i) if(x>=b[i].st && x<=b[i].ed){p=i;break;}
            if(!p) {puts("ERR");continue;}
            r=dfs(b[p].t,b[p].id,b[p].st,b[p].ed,x);
            cout<<r<<'\n';
        }
    }
    return 0;
}
