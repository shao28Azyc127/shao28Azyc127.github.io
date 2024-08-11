#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
#define rep(i,x,y) for(LL i=(x);i<=(y);i++)
using namespace std;
LL N;
string s;
bool vis[8005][8005];
stack<pair<char,LL> >St,clr;
queue<LL>Q;
vector<LL>G[8005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>s;s='#'+s;
    LL ans=0;
    rep(i,1,N){
        St=clr;
        LL K=0;
        rep(j,i,N){
            if(St.size()&&St.top().fi==s[j]){
                if(!vis[St.top().se][j+1]){
                    ans+=1;
                    G[St.top().se].push_back(j+1);
                //    cerr<<":"<<St.top().se<<"-"<<j+1<<endl;
                }
                vis[St.top().se][j+1]=1;St.pop();
            }else St.push(mp(s[j],j));
        }
    }
    rep(i,1,N){
        if(!G[i].size())continue;
        for(LL dt:G[i])Q.push(dt);
        while(Q.size()){
            LL nt=Q.front();Q.pop();
            for(LL dt:G[nt]){
                if(vis[i][dt])continue;
                Q.push(dt);vis[i][dt]=1;ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
