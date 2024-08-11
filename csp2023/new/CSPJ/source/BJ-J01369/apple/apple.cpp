#include <bits/stdc++.h>
using namespace std;
const int N=1e9+5;
int n,ans1,ans2,cnt=1;
bool vis[N];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int b=1;
    int c=0;
    while(cnt!=n){
        int cur=b;
        int cnt2=0;
        while(cur<=n){
            if(vis[cur]){
                cur++;continue;
            }
            if(cnt2%3==0) vis[cur]=1,c++;
            if(cur==n&&cnt2%3==0) ans2=cnt;
            cnt2++,cur++;
        }
        // for(int i=1;i<=n;i++){
        //     cout<<vis[i];
        // }
        // cout<<endl;
        cnt++,b++;
        if(c==n) break;
    }
    cout<<cnt-1<<" "<<ans2<<endl;
    return 0;
}