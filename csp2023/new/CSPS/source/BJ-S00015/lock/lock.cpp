#include<bits/stdc++.h>
using namespace std;
int n,a[10][6],b,c[100005],d[10]={0,10000,1000,100,10,1},e,ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            e=0;
            for(int k=1;k<=5;k++){
                if(k!=j){
                    e+=d[k]*a[i][k];
                }
            }
            for(int k=1;k<=9;k++){
                b=e;
                b+=(a[i][j]+k)%10*d[j];
                c[b]++;
            }
        }
        for(int j=1;j<=4;j++){
            e=0;
            for(int k=1;k<=5;k++){
                if(k!=j&&k!=j+1){
                    e+=d[k]*a[i][k];
                }
            }
            for(int k=1;k<=9;k++){
                b=e;
                b+=(a[i][j]+k)%10*d[j];
                b+=(a[i][j+1]+k)%10*d[j+1];
                c[b]++;
            }
        }
    }
    for(int i=0;i<=99999;i++){
        if(c[i]==n)ans++;
    }
    cout<<ans;
    return 0;
}
