#include<bits/stdc++.h>
using namespace std;
int vis[12][12][12][12][12],a[15][5];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
    int n,m=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=9;j++){
            vis[(a[i][1]+j)%10][a[i][2]][a[i][3]][a[i][4]][a[i][5]]+=1;
        }
        for(int j=1;j<=9;j++){
            vis[a[i][1]][(a[i][2]+j)%10][a[i][3]][a[i][4]][a[i][5]]+=1;
        }
        for(int j=1;j<=9;j++){
            vis[a[i][1]][a[i][2]][(a[i][3]+j)%10][a[i][4]][a[i][5]]+=1;
        }
        for(int j=1;j<=9;j++){
            vis[a[i][1]][a[i][2]][a[i][3]][(a[i][4]+j)%10][a[i][5]]+=1;
        }
        for(int j=1;j<=9;j++){
            vis[a[i][1]][a[i][2]][a[i][3]][a[i][4]][(a[i][5]+j)%10]+=1;
        }
        
        
        
        for(int j=1;j<=9;j++){
            vis[(a[i][1]+j)%10][(a[i][2]+j)%10][a[i][3]][a[i][4]][a[i][5]]+=1;
        }
        for(int j=1;j<=9;j++){
            vis[a[i][1]][(a[i][2]+j)%10][(a[i][3]+j)%10][a[i][4]][a[i][5]]+=1;
        }
        for(int j=1;j<=9;j++){
            vis[a[i][1]][a[i][2]][(a[i][3]+j)%10][(a[i][4]+j)%10][a[i][5]]+=1;
        }
        for(int j=1;j<=9;j++){
            vis[a[i][1]][a[i][2]][a[i][3]][(a[i][4]+j)%10][(a[i][5]+j)%10]+=1;
        }

    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int p=0;p<=9;p++){
                    for(int q=0;q<=9;q++){
                        if(vis[i][j][k][p][q]==n){
                            m++;
                        }
                    }
                }
            }
        }
    }
    printf("%d",m);
    return 0;
}