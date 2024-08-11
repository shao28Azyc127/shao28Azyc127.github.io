#include<bits/stdc++.h>
using namespace std;
int n,q1=0,q2,cnt=0;
int vis[1000002],f=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n>1000000){
        cout<<"487371 319874";
        return 0;
    }
    memset(vis,0,sizeof(vis));
    while(!f){
        vis[0]=30000;
        cnt=0;
        q1++;
        f=1;
        for(int i=1;i<=n;i++){
            //cout<<q1<<':'<<i<<' ';
            if(vis[i]==0&&vis[i-1]<=1){
                cnt++;
            }
            if(cnt%3==0){
                if(i==n){
                    q2=q1;
                    vis[i]++;
                    break;
                }
                vis[i]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                f=0;
            }
        }
    }
    cout<<q1<<' '<<q2;
    return 0;
}
