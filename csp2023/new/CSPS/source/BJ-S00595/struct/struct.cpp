#include<bits/stdc++.h>

using namespace std;

#define LL long long
const int NR=2e4+5;

string s[NR],t,tt;
int num; // m: duiqiyaoqiu
int tp[NR];
LL sz[NR],tot,m,pos[NR],sum[NR];
map<string,int> mp;
vector<int> g[NR];

LL getnum(LL x,LL y){
    if(x==0ll) return 0ll;
    return ((x-1ll)/y+1ll)*y;
}

void work1(){
    cin>>s[++num];
    mp[s[num]]=num;
    tp[num]=num;
    int k,tmp=num; m=0;
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>t;
        int x=mp[t];
        cin>>s[++num];
        tp[num]=x;
        sz[num]=sz[x];
        g[tmp].push_back(num);
        m=max(m,sz[x]);
        sum[tmp]+=sz[x];
    }
    sz[tmp]=getnum(sum[tmp],m);
    cout<<sz[tmp]<<' '<<m<<'\n';
}

void work2(){
    cin>>t;
    int x=mp[t];
    cin>>s[++num];
    g[0].push_back(num);
    tp[num]=x;
    pos[num]=getnum(tot,sz[x]);
    cout<<pos[num]<<'\n';
    tot=pos[num]+sz[x];
}

int now;
LL addr;

void solve(int x){
    if(!x){
        for(auto y:g[0]){
            if(s[y]==tt){
                addr=pos[y];
                now=tp[y];
                break;
            }
        }
        return;
    }
    for(auto y:g[x]){
        if(s[y]==tt){
            now=tp[y];
            break;
        }
        addr+=sz[y];
    }
}

void work3(){
    cin>>t;
    t=t+'.';
    int len=t.size(),p=0;
    now=addr=0;
    for(int i=0;i<len;i++){
        if(t[i]=='.'){
            tt.clear();
            for(int j=p;j<i;j++) tt=tt+t[j];
            p=i+1;
            solve(now);
        }
    }
    cout<<addr<<'\n';
}

bool flag;

void solve2(int x,int k){
    if(!g[x].size()) return;
    if(k>sum[x]){
        flag=0;
        printf("ERR\n");
        return;
    }
    for(auto y:g[x]){
        if(sz[y]>=k){
            x=y;
            break;
        }
        k-=sz[y];
    }
    tt=tt+"."+s[x];
    solve2(tp[x],k);
}

void work4(){
    cin>>addr; now=0;
    if(addr>=tot){
        printf("ERR\n");
        return;
    }
    for(auto x:g[0]){
        if(pos[x]>addr) break;
        now=x;
    }
    flag=1;
    tt=s[now];
    solve2(tp[now],addr-pos[now]+1);
    if(flag) cout<<tt<<'\n';
}

int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    s[1]="byte"; sz[1]=1;
    s[2]="short"; sz[2]=2;
    s[3]="int"; sz[3]=4;
    s[4]="long"; sz[4]=8;
    num=4;
    for(int i=1;i<=num;i++) mp[s[i]]=i;
    int T; cin>>T;
    while(T--){
        int o; cin>>o;
        if(o==1) work1();
        if(o==2) work2();
        if(o==3) work3();
        if(o==4) work4();
    }
    return 0;
}