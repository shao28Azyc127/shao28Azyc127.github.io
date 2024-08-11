#include<bits/stdc++.h>
using namespace std;
bool vis[810][810];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,ans=0,pos[810],cnt=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cnt++;
            pos[cnt]=i;
        }
    }
    if(cnt==0){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=cnt;i++) vis[pos[i]][pos[i]+1]=1;
    for(int t=1;t<=cnt;t++){
        for(int i=pos[t];i>=0;i--){
            for(int j=pos[t]+1;j<n;j++){
                bool flag=0;
                if((j-i)%2==1){
                    //cout<<i<<" "<<j<<endl;
                    if(vis[i+1][j-1]==1&&s[i]==s[j]) vis[i][j]=1,flag=1;
                    if(vis[i][j-2]==1&&s[j-1]==s[j]) vis[i][j]=1,flag=1;
                    if(vis[i+2][j]==1&&s[i]==s[i+1]) vis[i][j]=1,flag=1;
                    if(flag==0) for(int k=i+2;k<=j-2;k+=2) if(vis[i][k]==1&&vis[k+1][j]==1) vis[i][j]=1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            bool flag=0;
            if((j-i)%2==1){
                //cout<<i<<" "<<j<<endl;
                if(vis[i+1][j-1]==1&&s[i]==s[j]) vis[i][j]=1,flag=1;
                if(vis[i][j-2]==1&&s[j-1]==s[j]) vis[i][j]=1,flag=1;
                if(vis[i+2][j]==1&&s[i]==s[i+1]) vis[i][j]=1,flag=1;
                if(flag==0) for(int k=i+1;k<=j-1;k+=2) if(vis[i][k]==1&&vis[k+1][j]==1) vis[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            bool flag=0;
            if((j-i)%2==1){
                //cout<<i<<" "<<j<<endl;
                if(vis[i+1][j-1]==1&&s[i]==s[j]) vis[i][j]=1,flag=1;
                if(vis[i][j-2]==1&&s[j-1]==s[j]) vis[i][j]=1,flag=1;
                if(vis[i+2][j]==1&&s[i]==s[i+1]) vis[i][j]=1,flag=1;
                if(flag==0) for(int k=i+1;k<=j-1;k+=2) if(vis[i][k]==1&&vis[k+1][j]==1) vis[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                //cout<<vis[i][j]<<" ";
                ans+=vis[i][j];
            }
        //cout<<endl;
    }
    cout<<ans;
    return 0;
//  rp++
//  check scanf int use d ll use lld
//  dont scanf in nosync mode
}
