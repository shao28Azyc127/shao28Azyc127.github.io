#include<bits/stdc++.h>
using namespace std;
int vis[100005];
int a[9][6];
int n,cnt;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
            sum=sum*10+a[i][j];
        }
        vis[sum]=-99999;
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=99999;j++){
            int x[6];
            int aa[6]={0,j/10000,j/1000%10,j/100%10,j/10%10,j%10};
            int tong=0;
            for(int k=1;k<=5;k++){
                x[k]=(10+aa[k]-a[i][k])%10;
                if(x[k]!=0)tong++;
            }
            for(int k=1;k<=5;k++){
                if(tong==1&&x[k]!=0){
                    vis[j]++;
                    if(vis[j]==n){
                        cnt++;
                    }
                    break;
                }
                if(k<5&&tong==2&&x[k]!=0&&x[k+1]==x[k]){
                    vis[j]++;
                    if(vis[j]==n){
                        cnt++;
                    }
                    break;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
