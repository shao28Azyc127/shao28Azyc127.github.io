#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define repp(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,tot,col,siz[1000005],ssum,rsiz[1000005],dq[1000005];
bool pd[1000005];
string s,s2,ss[105],ss2[105],nm[1000005];
vector<ll> v[1000005];
vector<ll> v2[105];
map<string,ll> Mp;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%lld",&n);
    while(n--){
        ll op,k;
        scanf("%lld",&op);
        if(op==1){
            cin>>s;
            scanf("%lld",&k);
            Mp[s]=++col;
            rep(i,1,k) cin>>ss[i]>>ss2[i];
            rep(j,0,7){
                ll x=++tot,now=j;
                v2[col].pb(x);
                rep(i,1,k){
                    if(ss[i]=="byte"){
                        v[x].pb(++tot);
                        nm[tot]=ss2[i];
                        siz[tot]=1;
                        dq[tot]=1;
                    }
                    else if(ss[i]=="short"){
                        v[x].pb(++tot);
                        nm[tot]=ss2[i];
                        siz[tot]=2;
                        rsiz[tot]=now&1;
                        dq[tot]=2;
                    }
                    else if(ss[i]=="int"){
                        v[x].pb(++tot);
                        nm[tot]=ss2[i];
                        siz[tot]=4;
                        if(now&3) rsiz[tot]=4-(now&3);
                        dq[tot]=4;
                    }
                    else if(ss[i]=="long"){
                        v[x].pb(++tot);
                        nm[tot]=ss2[i];
                        siz[tot]=8;
                        if(now&7) rsiz[tot]=8-(now&7);
                        dq[tot]=8;
                    }
                    else{
                        ll y=v2[Mp[ss[i]]][now&7];
                        v[x].pb(++tot);
                        v[tot].pb(y);
                        pd[tot]=1;
                        siz[tot]=siz[y];
                        rsiz[tot]=rsiz[y];
                        dq[tot]=dq[y];
                        nm[tot]=ss2[i];
                    }
                    now+=siz[tot]+rsiz[tot];
                    now&=7;
                }
                rep(i,0,v[x].size()-1){
                    siz[x]+=rsiz[v[x][i]]+siz[v[x][i]];
                    dq[x]=max(dq[x],dq[v[x][i]]);
                }
                if(siz[x]%dq[x]) rsiz[x]=dq[x]-siz[x]%dq[x];
            }
            printf("%lld %lld\n",siz[v2[col][0]]+rsiz[v2[col][0]],dq[v2[col][0]]);
            //printf(".%lld\n",tot);
        }
        if(op==2){
            cin>>s>>s2;
            ll x=++tot;
            v[0].pb(x);
            if(s=="byte"){
                nm[x]=s2;
                siz[tot]=1;
            }
            else if(s=="short"){
                nm[x]=s2;
                rsiz[tot]=ssum&1;
                siz[tot]=2;
            }
            else if(s=="int"){
                nm[x]=s2;
                if(ssum&3) rsiz[tot]=4-(ssum&3);
                siz[tot]=4;
            }
            else if(s=="long"){
                nm[x]=s2;
                if(ssum&7) rsiz[tot]=8-(ssum&7);
                siz[tot]=8;
            }
            else{
                ll y=v2[Mp[s]][ssum&7];
                v[x].pb(y);
                pd[x]=1;
                siz[x]=siz[y];
                rsiz[x]=rsiz[y];
                nm[x]=s2;
            }
            printf("%lld\n",ssum);
            ssum+=siz[x]+rsiz[x];
        }
        if(op==3){
            ll now=0,ans=0;
            string S="";
            cin>>s;
            rep(i,0,s.size()-1){
                if(s[i]=='.'){
                    rep(j,0,v[now].size()-1){
                        if(nm[v[now][j]]!=S) ans+=rsiz[v[now][j]]+siz[v[now][j]];
                        else{
                            now=v[now][j];
                            break;
                        }
                    }
                    if(pd[now]) now=v[now][0];
                    S="";
                    continue;
                }
                S+=s[i];
            }
            rep(i,0,v[now].size()-1){
                if(nm[v[now][i]]!=S) ans+=rsiz[v[now][i]]+siz[v[now][i]];
                else{
                    if(!pd[v[now][i]])ans+=rsiz[v[now][i]];
                    break;
                }
            }
            printf("%lld\n",ans);
        }
        if(op==4){
            scanf("%lld",&k);
            if(k>=ssum){
                puts("ERR");
                continue;
            }
            ll now=0;
            bool qwq=0;
            string S="";
            while(1){
                bool p=0;
                rep(i,0,v[now].size()-1){
                    if(k>=siz[v[now][i]]+rsiz[v[now][i]]) k-=siz[v[now][i]]+rsiz[v[now][i]];
                    else{
                        now=v[now][i];
                        S+=nm[now];
                        if(pd[now]) now=v[now][0];
                        p=1;
                        break;
                    }
                }
                if(!p) qwq=1;
                if(qwq) break;
                if(v[now].empty()) break;
                S+='.';
                //break;
            }
            if(qwq) puts("ERR");
            else cout<<S<<endl;
        }
    }
    return 0;
}
/*

*/
