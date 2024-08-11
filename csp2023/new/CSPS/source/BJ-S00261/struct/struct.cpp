#include <bits/stdc++.h>
#define pii pair<int,int>
#define mkp(x,y) make_pair(x,y)
#define ll long long
using namespace std;
struct node{
    string t,name;
    vector <node> down;
    map <string,int> id;
    int type,mxt;
    ll bg,len;
    inline node() {id.clear(),down.clear(),bg=0,len=0,mxt=0,type=0; }
};
vector <node> now;
map <string,int> id;
map <ll,pii> addr;
int n;
ll st;
inline void solve1(){
    string nam,t,tn;
    int k;
    cin>>nam;
    scanf("%d",&k);
    node res; res.name=nam;
    now.push_back(res);
    int pos=now.size()-1;
    id[nam]=pos;
    int mxt=0;
    for (int i=1;i<=k;i++){
        cin>>t>>tn;
        if (t=="byte"){
            mxt=max(mxt,1);
            node nw;
            nw.type=1;
            nw.name=tn;
            nw.len=1;
            now[pos].down.push_back(nw);
            now[pos].id[tn]=now[pos].down.size()-1;
        }else if (t=="short"){
            mxt=max(mxt,2);
            node nw;
            nw.type=2;
            nw.name=tn;
            nw.len=2;
            now[pos].down.push_back(nw);
            now[pos].id[tn]=now[pos].down.size()-1;
        }else if (t=="int"){
            mxt=max(mxt,4);
            node nw;
            nw.type=3;
            nw.name=tn;
            nw.len=4;
            now[pos].down.push_back(nw);
            now[pos].id[tn]=now[pos].down.size()-1;
        }else if (t=="long"){
            mxt=max(mxt,8);
            node nw;
            nw.type=4;
            nw.name=tn;
            nw.len=8;
            now[pos].down.push_back(nw);
            now[pos].id[tn]=now[pos].down.size()-1;
        }
    }
    ll org=st;
    for (int i=0;i<now[pos].down.size();i++){
        node x=now[pos].down[i];
        st=((ll)(st+x.len-2)/mxt+1)*mxt;
    }
    now[pos].mxt=mxt;
    now[pos].len=st-org;
    st=org;
    printf("%lld %lld\n",now[pos].len,mxt);
}
inline void solve2(){
    string t,tn;
    cin>>t>>tn;
    if (t=="byte"){
        node res;
        res.name=tn;
        res.bg=st;
        res.type=1;
        res.mxt=1;
        res.len=1;
        now.push_back(res);
        addr[st]=mkp(now.size(),-1);
        printf("%lld\n",st);
        st+=res.len;
    }else if (t=="short"){
        node res;
        res.name=tn;
        res.bg=st;
        res.type=2;
        res.mxt=2;
        res.len=2;
        now.push_back(res);
        addr[st]=mkp(now.size(),-1);
        printf("%lld\n",st);
        st+=res.len;
    }else if (t=="int"){
        node res;
        res.name=tn;
        res.bg=st;
        res.type=3;
        res.mxt=4;
        res.len=4;
        now.push_back(res);
        addr[st]=mkp(now.size(),-1);
        printf("%lld\n",st);
        st+=res.len;
    }else if (t=="long"){
        node res;
        res.name=tn;
        res.bg=st;
        res.type=4;
        res.mxt=8;
        res.len=8;
        now.push_back(res);
        addr[st]=mkp(now.size(),-1);
        printf("%lld\n",st);
        st+=res.len;
    }else{
        printf("%lld\n",st);
        int pos=id[t];
        now[pos].bg=st;
        for (int i=0;i<now[pos].down.size();i++){
            node x=now[pos].down[i];
            now[pos].down[i].bg=st;
            addr[st]=mkp(pos,i);
            st=((ll)(st+x.len-2)/now[pos].mxt+1)*now[pos].mxt;
        }
    }
    id[tn]=now.size()-1;
}
inline void solve3(){
    string t;
    cin>>t;
    for (int i=0;i<t.size();i++){
        if (t[i]=='.'){
            string x=t.substr(0,i+1),y=t.substr(i+1,t.size()-i-1);
            printf("%d\n",now[id[x]].down[now[id[x]].id[y]].bg);
            break;
        }
    }
}
inline void solve4(){
    ll x0;
    scanf("%lld",&x0);
    printf("ERR\n");
    return ;
    /*
    map <ll,pii>::iterator it=addr.upper_bound(x0);
    it--;
    pii x=*it;
    string nm0="",nm1="";
    ll bg=0,len=0;
    if (x.second==-1){
        bg=now[x.first].bg;
        len=now[x.first].len;
        nm0=now[x.first].name;
    }else{
        bg=now[x.first].down[x.second].bg;
        len=now[x.first].down[x.second].len;
        nm0=now[x.first].name;
        nm1=now[x.first].down[x.second].name;
    }
    if (bg+len-1<x0){
        printf("ERR\n");
        return ;
    }
    if (nm1=="") printf("%s\n",nm0.c_str());
    else printf("%s.%s\n",nm0.c_str(),nm1.c_str());
        */
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    for (int i=1,opt;i<=n;i++){
        scanf("%d",&opt);
        if (opt==1) solve1();
        else if (opt==2) solve2();
        else if (opt==3) solve3();
        else if (opt==4) solve4();
    }
    return 0;
}
