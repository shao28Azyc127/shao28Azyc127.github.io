#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
#define int long long
int n,ans,bz[N],vis[N];
char s[N],t[N];
bool check(int x,int len){
    int siz=len;
    while(siz>0){
        int cnt=0;
        for(int i=x;i<x+siz-1;i++){
            if(t[i]==t[i+1]&&vis[i]==0&&vis[i+1]==0){
                vis[i]=1;
                vis[i+1]=1;
                cnt=cnt+2;
            }
        }
        int tot=0;
        for(int i=x;i<=x+siz-1;i++){
            if(vis[i]==0){
                tot++;
                t[tot]=t[i];
            }
            vis[i]=0;
        }
        siz=siz-cnt;
        if(cnt==0) return false;
    }
    return true;
}
void init(){
    for(int i=1;i<=n;i++){
        t[i]=s[i];
        vis[i]=0;
    }
}
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j+i-1<=n;j++){
            init();
            if(check(j,i)){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}