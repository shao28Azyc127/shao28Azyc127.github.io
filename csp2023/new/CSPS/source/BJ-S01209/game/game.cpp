#include<bits/stdc++.h>
using namespace std;
char a[2000007];
int ans=0,n,cnt=0;
int check(int l,int r){
    int b[2000007];
    for(int k=l;k<r;k++) {
        b[k]=int(a[k]);
    }
    int fl=1;
    while(fl>0){
        fl=0;
        for(int k=l;k<r;k++) {
            if(b[k]==b[k+1]&&b[k]!=0&&b[k+1]!=0) {
                fl=1;
                for(int q=k;q<=r;q++){
                    b[q]=b[q+2];
                }
            }
        }
    }
    return b[l];
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n+1;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n+1;i++){
        for(int j=i+2;j<=n+1;j+=2){
            if(!check(i,j)) {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
