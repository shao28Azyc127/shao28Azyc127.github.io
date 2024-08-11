#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const ll N=1e2+10,K=1e7+10;
string name[N],sname[N],stn;
ll cnt,pos[N],p[K],sz[N],st[N],dq=1,siz,apos,k,isstu[K];
ll cha(string s){
    if(s=="byte"){
        return 1;
    }else if(s=="short"){
        return 2;
    }else if(s=="int"){
        return 4;
    }else if(s=="long"){
        return 8;
    }else{
        return siz;
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ll n;
    scanf("%lld",&n);
    for(ll kk=1;kk<=n;kk++){
        ll op;
        scanf("%lld",&op);
        if(op==1){
            cin>>stn;
            ll tpp=0;
            scanf("%lld",&k);
            for(ll j=1;j<=k;j++){
                string typ;
                cin>>typ>>sname[j];
                ll tp=cha(typ);
                tpp=(tpp+tp-1)/tp*tp;
                st[j]=tpp,sz[j]=tp;
                tpp+=sz[j];
                dq=max(dq,tp);
            }
            siz=(tpp+dq-1)/dq*dq;
        }else if(op==2){
            string typ;
            cin>>typ>>name[++cnt];
            ll tp=cha(typ);
            apos=(apos+dq-1)/dq*dq;
            ll tp2=apos;
            pos[cnt]=apos;
            if(typ!=stn){
                for(;apos<tp2+tp;apos++){
                    p[apos]=cnt;
                }
            }else{
                for(ll i=1;i<=k;i++){
                    for(ll j=st[i]+apos;j<st[i]+sz[i]+apos;j++){
                        p[j]=i,isstu[j]=cnt;
                    }
                }
                apos+=siz;
            }
        }else if(op==3){
            string s;
            cin>>s;
            for(ll i=1;i<=cnt;i++){
                if(name[i]==s){
                    printf("%lld\n",pos[i]);
                    break;
                }
            }
        }else{
            ll addr;
            scanf("%lld",&addr);
            if(addr>=K||p[addr]==0){
                printf("ERR\n");
            }else if(isstu[addr]>0){
                cout<<name[isstu[addr]]<<"."<<sname[p[addr]]<<"\n";
            }else{
                cout<<name[p[addr]]<<"\n";
            }
        }
    }
    return 0;
}
