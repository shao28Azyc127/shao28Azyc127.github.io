#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,day,la,ans,vis[N];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int t=n;
    while(t){
        la=-1;
        for(int i=1;i<=n;i++){
            if((la==-1||la==2)&&!vis[i]){
                la=0;
                vis[i]=1;
                t--;
                if(i==n)ans=day+1;
            }else if(!vis[i])la++;
        }
        day++;
    }
    cout<<day<<" "<<ans;
    return 0;
}
