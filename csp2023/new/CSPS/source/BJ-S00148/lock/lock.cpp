//play florr.io and tkk!
//written by a fan of Robert_Lewandovski
#include<bits/stdc++.h>
using namespace std;
const int mod=10;
int n,a[10][10],b[10],tmp[10],ans;
map<int,int> mp;
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
        int x=0;
        for(int j=1;j<=5;j++){
            x=x*10+a[i][j];
        }
        b[i]=x;
        mp[x]--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            for(int k=1;k<=9;k++){
                tmp[j]=(a[i][j]+k)%mod;
                for(int l=1;l<=5;l++){
                    if(l==j) continue;
                    tmp[l]=a[i][l];
                }
                int x=0;
                for(int l=1;l<=5;l++){
                    x=x*10+tmp[l];
                }
                mp[x]++;
             //   cout<<x<<endl;
            }
        }
        for(int j=1;j<=4;j++){
            for(int k=1;k<=9;k++){
                tmp[j]=(a[i][j]+k)%mod;
                tmp[j+1]=(a[i][j+1]+k)%mod;
                for(int l=1;l<=5;l++){
                    if(l==j||l==j+1) continue;
                    tmp[l]=a[i][l];
                }
                int x=0;
                for(int l=1;l<=5;l++){
                    x=x*10+tmp[l];
                }
                mp[x]++;
             //   cout<<x<<endl;
            }
        }
    }
    for(int i=0;i<=99999;i++){
        if(mp[i]==n){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
