#include<bits/stdc++.h>
using namespace std;
struct IO{
    IO(){
        freopen("struct.in","r",stdin);
        freopen("struct.out","w",stdout);
    }
    ~IO(){
        fclose(stdin);
        fclose(stdout);
    }
}io;
typedef long long ll;
const int N=107;
int nn;
int op,k,tot;
string s,t[N],n[N];
unordered_map<string,int>id;//id of type
unordered_map<string,ll>siz;//typename->siz_of_type
unordered_map<string,ll>al;//alignment
struct var{
    string type,nm;
    ll l,r;//actual space used
};
vector<var>g[N];//id of type->name of each thing under
ll mem=0;
inline bool basic(string s){
    if(s=="byte"||s=="short"||s=="long"||s=="int"){
        return true;
    }
    return false;
}
struct rng{
    ll l,r;
    string nm;
};
unordered_map<string,rng>ans;
unordered_map<string,string>tp;//var name->type
void dfs(string name,string type,int l,int r){
    if(basic(type)){
        return;
    }
    int b=l;
    for(int i=0;i<g[id[type]].size();i++){
        var x=g[id[type]][i];
        if(i!=0){
            while(b%(al[x.type])){
                b++;
            }
        }
        string tmp=name+"."+x.nm;
        ans[tmp]={b,b+siz[x.type]-1,tmp};
        tp[tmp]=x.type;
        //cout<<tmp<<"   "<<ans[tmp].l<<"~"<<ans[tmp].r<<'\n';
        dfs(tmp,x.type,b,b+siz[x.type]-1);//
        b+=siz[x.type];
    }
}
ll addr;
ll b[N],opt=0;
int main(){
    cin>>nn;
    id["byte"]=1,id["short"]=2,id["int"]=3,id["long"]=4;
    siz["byte"]=1,siz["short"]=2,siz["int"]=4,siz["long"]=8;
    al["byte"]=1,al["short"]=2,al["int"]=4,al["long"]=8;
    tot=4;
    while(nn--){
        cin>>op;
        if(op==1){
            mem=0;
            cin>>s>>k;
            id[s]=++tot;
            ll cnt=0;
            for(int i=1;i<=k;i++){
                cin>>t[i]>>n[i];
                cnt=max(cnt,al[t[i]]);
                al[s]=max(al[s],al[t[i]]);
            }
            g[tot].push_back({t[1],n[1],mem,mem+siz[t[1]]-1});
            mem+=siz[t[1]];
            ll o=0;
            for(int i=2;i<=k;i++){
                o+=siz[t[i-1]];
                while((o%al[t[i]])!=0){
                    o++;
                }
                mem+=o;
                g[tot].push_back({t[i],n[i],mem,mem+siz[t[i]]-1});
            }
            o+=siz[t[k]];
            while(o%cnt!=0){
                o++;
            }
            siz[s]=o;
            cout<<siz[s]<<' '<<cnt<<'\n';
        }else if(op==2){
            cin>>t[1]>>n[1];
            opt++;
            if(opt==1){
                b[opt]=0;
            }else{
                while(b[opt]%al[t[1]]){
                    b[opt]++;
                }
            }
            ans[n[1]]={b[opt],b[opt]+siz[t[1]]-1,n[1]};
            tp[n[1]]=t[1];
            dfs(n[1],t[1],b[opt],b[opt]+siz[t[1]]-1);
            cout<<b[opt]<<'\n';
            b[opt+1]=b[opt]+siz[t[1]];
        }else if(op==3){
            cin>>s;
            cout<<ans[s].l<<'\n';
        }else{
            cin>>addr;
            string res="";
            ll minlen=LLONG_MAX;
            for(auto p:ans){
                if(addr>=p.second.l&&addr<=p.second.r){
                    if(basic(tp[p.second.nm])){
                        minlen=min(minlen,p.second.r-p.second.l+1);
                        res=p.second.nm;
                    }
                }
            }
            if(minlen!=LLONG_MAX){
                cout<<res<<'\n';
            }else{
                cout<<"ERR"<<'\n';
            }
        }
    }
    return 0;
}
