#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[3010];
int a[3010][27];
int ax[3010];
int ad[3010];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m-1;j++){
            a[i][(s[i][j]-'0')-48]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=26;j++){
            if(a[i][j]!=0){
                ax[i]=j;
                break;
            }
        }
        for(int j=26;j>=1;j--){
            if(a[i][j]!=0){
                ad[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        bool f=true;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(ax[i]<ad[j])continue;
            if(ax[i]>=ad[j]){
                cout<<0;
                f=false;
                break;
            }
        }
        if(f==true)cout<<1;
    }
    return 0;
}