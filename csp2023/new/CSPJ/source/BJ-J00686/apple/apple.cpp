#include <bits/stdc++.h>
using namespace std;
int n,first=1;
bool vis[100000010];
void dfs(int x){
    vis[x]=true;
    //cout<<x<<endl;
    int i=0;
    while(i!=3){
        if(vis[++x])continue;
        i++;
    }
    if(x<=n)dfs(x);
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int ans,i=0;
    bool flag=true;
    //cout<<345<<' ';
    int p=0;
    while(true){
        if(first>n)break;
        i++;
        dfs(first);
        if(vis[n] && ++p==1)ans=i;
        bool l=true;
        int k=1;
        while(l){
            l=vis[k];
            first=k;
            k++;
        }
        flag=true;
        for(int i=0;i<n;i++)flag=flag&&vis[i];
        //cout<<flag<<' ';
        if(flag)break;
    }
    cout<<i<<' '<<ans<<endl;
    //return 0;
}
