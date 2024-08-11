#include<bits/stdc++.h>
using namespace std;
int n,ans,nu,cnt,cnt1,a[1000005][3],k=1,i;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i][0]=i;
    }
    cnt=n;
    while(cnt){
        ans++;
        for(i=1;i<=cnt;i++){
            if(i==1) continue;
            if(k==1){
                if((i-1)%3==0&&a[i][0]==n) nu=ans;
                if((i-1)%3) a[++cnt1][k]=a[i][0];
            }else{
                if((i-1)%3==0&&a[i][1]==n) nu=ans;
                if((i-1)%3) a[++cnt1][k]=a[i][1];
            }
        }
        if(k==1){
            if(a[1][0]==n) nu=ans;
        }else{
            if(a[1][1]==n) nu=ans;
        }
        cnt=cnt1;
        cnt1=0;
        if(k) k=0;
        else k=1;
    }
    cout<<ans<<" "<<nu;
    return 0;
}

