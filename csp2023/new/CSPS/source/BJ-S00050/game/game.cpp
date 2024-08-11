#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,cnt[2000005],mxend[2000005];
char a[2000005];
long long ans;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            cnt[i]++;
            mxend[i]=i+1;
        }
    }
    for(int i=n;i>=1;i--){
        if(cnt[i]==0)continue;
        if(a[i-1]==a[mxend[i]+1]){
            cnt[i-1]++;
            mxend[i-1]=max(mxend[i-1],mxend[i]+1);
        }
        cnt[i]+=cnt[mxend[i]+1];
        mxend[i]=mxend[mxend[i]+1];
    }
    for(int i=1;i<=n;i++)ans+=cnt[i];
    //for(int i=1;i<=n;i++)cout<<cnt[i]<<' ';
    //cout<<endl;
    //for(int i=1;i<=n;i++)cout<<mxend[i]<<' ';
    cout<<ans<<endl;
    return 0;
}
