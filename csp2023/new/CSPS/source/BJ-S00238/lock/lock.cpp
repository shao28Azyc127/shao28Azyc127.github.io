#include <bits/stdc++.h>
using namespace std;
int a[10][10],n;
int f[5][10][10];
int cnt[5];
int ans,d;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    }
    bool fl=true;
    for(int i=1;i<=5;i++){
        for(int j=2;j<=n;j++){
            if(a[j][i]!=a[j-1][i]){
                fl=false;
                break;
            }
        }
    }
    if(fl){
        cout<<81;
        return 0;
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(a[k][i]!=a[j][i]){
                    cnt[i]++;
                }
            }
        }
    }
    for(int i=1;i<=5;i++){
        if(cnt[i]>0){
            ans+=(10-cnt[i]);
        }
    }
    cout<<ans;
    return 0;
}
