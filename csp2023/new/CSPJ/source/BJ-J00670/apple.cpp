#include <bits/stdc++.h>
using namespace std;
const int N=1000000+10;
int vis[N];

void test(){
    int n;cin>>n;
    int tme=0,tn=n;
    while(tn){
        tme++;
        tn-=(tn+2)/3;
    }
    //cout<<tme<<endl;return;
    int ans2;
    for(int i=1;i<=tme;i++){
        int cnt=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j])cnt++;
            if(cnt%3==0&&!vis[j]){
                vis[j]=1;
                if(j==n)ans2=i;
                //cout<<n<<","<<j<<": "<<ans2<<endl;
            }
        }
        //cout<<i<<": "<<ans2<<endl;
    }
    cout<<tme<<" "<<ans2<<endl;
}

signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    test();
    return 0;
}
