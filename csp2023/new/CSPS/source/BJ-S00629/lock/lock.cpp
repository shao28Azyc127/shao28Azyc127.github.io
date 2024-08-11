#include<bits/stdc++.h>
using namespace std;
int n,a[11][11],vis[11][11][11][11][11],ans=0;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=9;j++){
            vis[j][a[i][2]][a[i][3]][a[i][4]][a[i][5]]++;
        }
        for(int j=0;j<=9;j++){
            vis[a[i][1]][j][a[i][3]][a[i][4]][a[i][5]]++;
        }
        for(int j=0;j<=9;j++){
            vis[a[i][1]][a[i][2]][j][a[i][4]][a[i][5]]++;
        }
        for(int j=0;j<=9;j++){
            vis[a[i][1]][a[i][2]][a[i][3]][j][a[i][5]]++;
        }
        for(int j=0;j<=9;j++){
            vis[a[i][1]][a[i][2]][a[i][3]][a[i][4]][j]++;
        }
        for(int j=0;j<=9;j++){
            vis[(a[i][1]+j)%10][(a[i][2]+j)%10][a[i][3]][a[i][4]][a[i][5]]++;
        }
        for(int j=0;j<=9;j++){
            vis[a[i][1]][(a[i][2]+j)%10][(a[i][3]+j)%10][a[i][4]][a[i][5]]++;
        }
        for(int j=0;j<=9;j++){
            vis[a[i][1]][a[i][2]][(a[i][3]+j)%10][(a[i][4]+j)%10][a[i][5]]++;
        }
        for(int j=0;j<=9;j++){
            vis[a[i][1]][a[i][2]][a[i][3]][(a[i][4]+j)%10][(a[i][5]+j)%10]++;
        }
        vis[a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]]=0;
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    for(int g=0;g<=9;g++){
                        if(vis[i][j][k][l][g]==n){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
