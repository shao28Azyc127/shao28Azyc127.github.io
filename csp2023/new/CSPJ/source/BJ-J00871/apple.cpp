#include<bits/stdc++.h>
using namespace std;
int n,vis[10000001],ans=0,ret=0,cnt=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(cnt<n){
        ans++;
        int i=1;
        while(i<=n){
            if(vis[i]==0){
                cnt++;
                vis[i]=1;
                if(i==n){
                    ret=ans;
                }
                int x=0;
                while(i<=n){
                    if(x==2){
                        break;
                    }
                    if(vis[i]==0){
                        x++;
                    }
                    i++;
                }
            }else{
                i++;
            }
        }
    }
    cout<<ans<<" "<<ret;
    return 0;
}
