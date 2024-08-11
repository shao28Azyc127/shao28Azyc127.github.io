/*
  hmz is cute!
---------------------------
  You've got to have faith
  Don't let them cut you down cut you down once more
*/
#include<bits/stdc++.h>
using namespace std;
#define TY int
#define ll long long
#define INF (TY)(1e9)
#define mod (TY)(1e9+7)
#define pb push_back
#define IL inline
#define MAXN 200005
#define MAXM 200005
#define MAXK 27
#define For(i,a,b) for(TY i=(a);i<=(b);++i)
#define FOR(i,a,b) for(TY i=(a);i<(b);++i)
#define Rof(i,a,b) for(TY i=(a);i>=(b);--i)
#define ROF(i,a,b) for(TY i=(a);i>(b);--i)
IL TY qr(){
    TY u=0,v=1;char ch=getchar();
    while(ch<'0'||ch>'9')v=(ch=='-'?-1:1),ch=getchar();
    while(ch>='0'&&ch<='9')u=u*10+(ch-'0'),ch=getchar();
    return u*v;
}IL void qw(TY now){
    if(now<0){putchar('-');now=-now;}
    if(!now){putchar('0');return;}
    if(now>=10)qw(now/10);putchar('0'+now%10);
}IL void qw(TY now,char ch){qw(now);putchar(ch);}
IL bool ischar(char ch){return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||ch=='+'||ch=='-';}
IL char getc(){
    char ch=getchar();
    while(!ischar(ch))ch=getchar();
    return ch;
}IL string qs(){
    string lst="";char ch=getchar();
    while(!ischar(ch))ch=getchar();
    while(ischar(ch))lst+=ch,ch=getchar();
    return lst;
}IL void ws(string s){FOR(i,0,s.size())putchar(s[i]);}
IL TY Mod(TY k){return (k>=mod?k-mod:k);}
IL TY Ceil(TY x,TY y){return x/y+(x%y!=0);}
IL TY Pow(TY a,TY b){
    TY base=a,ans=1;
    while(b){
        if(b&1)ans=ans*base%mod;
        base=base*base%mod;
    }return ans;
}TY id,T,n,m,belong[MAXN],cnt[MAXN],siz[MAXN],in[MAXN],fir,sec;
vector<pair<TY,TY> > e[MAXN];queue<TY> q;bool vis[MAXN];
IL void Pb(TY i,TY j,TY k){e[i].pb({j,k});++in[j];}
void dfs(TY now){
    vis[now]=1;
    sec+=siz[now];
    FOR(i,0,e[now].size()){
        TY y=e[now][i].first;
        if(in[y])fir+=e[now][i].second;
        if(!vis[y])dfs(y);
    }
}IL void solve(){
    For(i,1,n+3)if(!in[i])q.push(i);
    while(!q.empty()){
        TY now=q.front();
        q.pop();FOR(i,0,e[now].size()){
            TY y=e[now][i].first;
            --in[y];siz[y]+=siz[now];
            if(!in[y])q.push(y);
        }
    }
}IL void clear(){
    For(i,1,n+3)belong[i]=i,cnt[i]=in[i]=vis[i]=0,siz[i]=1,e[i].clear();
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);

    /* init */
    id=qr();T=qr();while(T--){
        TY ans=0;n=qr();m=qr();
        clear();
        For(i,1,m){
            char op=getc();TY u,v;
            if(op=='T'){
                u=qr();belong[u]=n+1;
                cnt[u]=0;
            }else if(op=='F'){
                u=qr();belong[u]=n+2;
                cnt[u]=0;
            }else if(op=='U'){
                u=qr();belong[u]=n+3;
                cnt[u]=0;
            }else if(op=='+'){
                u=qr();v=qr();
                belong[u]=belong[v];
                cnt[u]=cnt[v];
            }else{
                u=qr();v=qr();
                belong[u]=belong[v];
                cnt[u]=cnt[v]+1;
            }
        }For(i,1,n)Pb(i,belong[i],cnt[i]%2);
        solve();For(i,1,n)if(!vis[i]&&in[i]){
            fir=sec=0;dfs(i);
            if(fir%2==1)ans+=sec;
        }ans+=siz[n+3]-1;qw(ans,'\n');
    }
    return 0;
}