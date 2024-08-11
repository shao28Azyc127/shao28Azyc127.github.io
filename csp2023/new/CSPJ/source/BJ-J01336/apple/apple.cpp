#include<bits/stdc++.h>
using namespace std;
#define int long long
bool vis [1000100],f;
int sum,ts;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,a=0,s=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&a==0){
            a=1;
            vis[i]=1;
            if(i==n){
                    sum=ts;
                }
        }
        if(vis[i]==0){
            s++;
            if(s==3){
                vis[i]=1;
                s=0;
                if(i==n){
                    sum=ts;
                }
            }
        }
        if(i==n){
                f=0;a=0;ts++;s=0,i=0;
        }
        for(int j=1;j<=n;j++){
                if(vis[j]==0){
                    f=1;
                    break;
                }
            }
            if(!f) break;
        //for(int d=1;d<=n;d++){
         //   cout<<vis[d];
        //}
       //cout<<endl;
        //cout<<ts;
        //cout<<endl;
    }
    cout<<ts<<" "<<sum+1;


    return 0;
}
