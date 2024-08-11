#include<iostream>
#include<map>
#include<string>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
bool vis[200000];
bool breakable(string a){
    int len=a.length();
    for(int k=0;k<len;k++){
        memset(vis,0,sizeof(vis));
        len=a.length();
        for(int i=0;i<len-1;i++){
            if(a[i]==a[i+1]){
                vis[i]=1;
                vis[i+1]=1;
                i++;
            }
        }
        string tmp="";
        for(int i=0;i<len;i++){
            if(vis[i]==0) tmp+=a[i];
            vis[i]==0;
        }
        if(tmp==a) break;
        a=tmp;
    }
    if(a=="") return 1;
    return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,ans=0;
    cin>>n;
    string a;
    cin>>a;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            string tmp=a.substr(i,j);
            if(breakable(tmp)) ans++;
        }
    }
    cout<<ans;
    return 0;
}

