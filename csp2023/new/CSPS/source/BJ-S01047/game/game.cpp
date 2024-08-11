#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e6+10;
long long n,ans;
bool vis[maxn];
string s;
void BOOM(int k,int st,int ed){
    //cout<<"*************************"<<endl;
    int i=k,j=k+1;
    while(i>=st && j<=ed && s[i]==s[j] && vis[i]==0 && vis[j]==0){
        //cout<<i<<' '<<j<<endl;
        vis[i]=vis[j]=1,i--,j++;
    }
    //cout<<"*************************"<<endl;
    return;
}
long long hui(long long st,long long ed){
    //if((ed-st+1)%2!=0) return 0;
    memset(vis,0,sizeof(vis));
    for(int i=st;i<ed;i++){
        if(s[i]==s[i+1] && !vis[i] && !vis[i+1]) BOOM(i,st,ed);

    }
//    cout<<st<<' '<<ed<<endl;
//    for(int i=st;i<=ed;i++) cout<<vis[i]<<' ';
//    cout<<endl;
//    for(int i=st;i<=ed;i++) cout<<s[i]<<' ';
//    cout<<endl;
    for(int i=st;i<=ed;i++){
        if(!vis[i]) return 0;
    }
    //if((ed-st+1)%2!=0) cout<<"shit"<<endl;
    return 1;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans+=hui(i,j);
        }
    }
    cout<<ans<<endl;
    return 0;
}
