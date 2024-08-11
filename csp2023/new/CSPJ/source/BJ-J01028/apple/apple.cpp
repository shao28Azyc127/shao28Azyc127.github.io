#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cnt[N];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    //for(int n=1;n<=1e4;n++){
    for(int i=1;i<=n;i++)cnt[i]=i%3;
    int ans=0;
    int d=0;
    while(1){
        ans++;
        int tmp=1;
        for(int i=1;i<=n;i++){
            if(cnt[i]==1){
                cnt[i]=-1;
                if(i==n)d=ans;
                //cout<<i<<" ";
            }
            else if(cnt[i]!=-1){
                if(tmp==3)tmp=0;
                cnt[i]=tmp;
                tmp++;
            }
        }
        //cout<<"\n";
        int flag=0;
        for(int i=1;i<=n;i++){
            if(cnt[i]!=-1)flag=1;
        }
        if(flag==0){
            break;
        }
    }
    cout<<ans<<" "<<d<<"\n";
    //}
    return 0;
}
