#include <bits/stdc++.h>
using namespace std;
int n,d,t,s,ans;
bool vis[1000000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    s=n;
    while(s){
        d++;
        t=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(t%3==0){
                    s--;
                    vis[i]=1;
                    if(i==n)ans=d;
                }
                t++;
            }
        }
    }
    cout<<d<<" "<<ans;
    return 0;
}
