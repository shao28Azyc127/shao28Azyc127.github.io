#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,x,y) for(LL i=(x);i<=(y);i++)
#define per(i,x,y) for(LL i=(x);i>=(y);i--)
#define all(x) x.begin(),x.end()
LL N,M,tng[30];string s[3005],t[3005],minn,minn2;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("dict.in","r",stdin);freopen("dict.out","w",stdout);
    cin>>N>>M;
    if(N==1){cout<<1<<'\n';return 0;}
    rep(i,1,N)cin>>s[i];
    rep(i,1,N){
        memset(tng,0,sizeof tng);
        for(char x:s[i])tng[x-'a']++;
        s[i]="";
        rep(j,0,25)rep(k,1,tng[j])s[i]+=(char)(j+'a');
        per(j,25,0)rep(k,1,tng[j])t[i]+=(char)(j+'a');
    }
    rep(i,1,M)minn+='z',minn2+='z';
    rep(i,1,N){
        if(minn>t[i]){
            minn2=minn;
            minn=t[i];
            continue;
        }
        if(minn2>t[i])minn2=t[i];
    }
    rep(i,1,N){
        if(minn==s[i]){
            if(minn2>s[i])cout<<'1';else cout<<'0';
            continue;
        }
        if(minn>s[i])cout<<'1';else cout<<'0';
    }cout<<'\n';
    return 0;
}
//You're a slave to the history
