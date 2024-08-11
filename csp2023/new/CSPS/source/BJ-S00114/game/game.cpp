#include<bits/stdc++.h>
using namespace std;

map<string,bool> mp;
int n;
bool dfs(string x){
    if(mp[x])
        return mp[x]==1;
    cout<<x<<endl;
    for(int i=0;i+1<x.size();i++){
        if(x[i]==x[i+1]){
            string d=x.erase(i,2);
            bool f=dfs(d);
            if(f){
                mp[x]=1;
                break;
            }
        }
    }
    if(!mp[x])
        mp[x]==-1;
    return mp[x]==1;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int ans=0;
    string s;
    cin>>n>>s;
    mp.clear();
    mp[""]=1;

    for(int l=2;l<=n;l++){
        for(int i=0;i+l<=n;i++){
            ans+=dfs(s.substr(i,l));
        }
    }
    cout<<ans;
    return 0;
}
