#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <ctime>
using namespace std;
#define ll long long
#define ull unsigned long long
ll read(){
    ll x=0,k=1;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-') k=-1,c=getchar();
    for(;'0'<=c&&c<='9';x=(x<<1)+(x<<3)+c-'0',c=getchar());
    return x*k;
}
struct Trie{
    int ch[2000006][26];
    int fa[2000006],s[2000006],v[2000006],cnt=0,now=0;
    void clear(){
        while(cnt){
            ch[fa[cnt]][v[cnt]]=0;
            s[cnt]=fa[cnt]=v[cnt]=0;
            cnt--;
        }
        for(int i=0;i<26;i++) ch[0][i]=0; s[0]=v[0]=now=0;
    }
    void ins(char c){
        if(!ch[now][c-'a']){
            ch[now][c-'a']=++cnt; fa[cnt]=now,v[cnt]=c-'a';
        }
        now=ch[now][c-'a'];
    }
    void del(){
        now=fa[now];
    }
    void add(char c){
        if(now&&c-'a'==v[now]) del();
        else ins(c); 
        s[now]++;
    }
    int solve(char c){
        if(now&&c-'a'==v[now]) del();
        else ins(c); 
        return s[now];
    }
}t;
int n;
char c[2000006];
ll ans=0;

void solve(int l,int r){
    if(l==r) return;
    int mid=l+r>>1;
    solve(l,mid),solve(mid+1,r);
    t.clear();
    for(int i=mid;i>=l;i--){
        t.add(c[i]);
    }
    t.now=0;
    for(int i=mid+1;i<=r;i++){
        ans+=t.solve(c[i]);
    }
    // cout<<l<<" "<<r<<" "<<ans<<endl;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char ch=getchar();
        for(;ch>'z'||ch<'a';ch=getchar());
        c[i]=ch;
    }
    solve(1,n);
    cout<<ans<<endl;
    return 0;
}