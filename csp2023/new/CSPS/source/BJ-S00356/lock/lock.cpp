#include<bits/stdc++.h>
using namespace std;
int n,a[10][10],b[11][11][11][11][11]={},ans=0;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++)scanf("%d",&a[i][j]);
        for(int j=1;j<=5;j++){
            if(j==1){
                for(int k=0;k<=9;k++){
                    if(k==a[i][j])continue;
                    b[k][a[i][2]][a[i][3]][a[i][4]][a[i][5]]++;
                }
                for(int k=1;k<=9;k++){
                    b[(a[i][1]+10-k)%10][(a[i][2]+10-k)%10][a[i][3]][a[i][4]][a[i][5]]++;
                }
            }else if(j==2){
                for(int k=0;k<=9;k++){
                    if(k==a[i][j])continue;
                    b[a[i][1]][k][a[i][3]][a[i][4]][a[i][5]]++;
                }
                for(int k=1;k<=9;k++){
                    b[a[i][1]][(a[i][2]+10-k)%10][(a[i][3]+10-k)%10][a[i][4]][a[i][5]]++;
                }
            }else if(j==3){
                for(int k=0;k<=9;k++){
                    if(k==a[i][j])continue;
                    b[a[i][1]][a[i][2]][k][a[i][4]][a[i][5]]++;
                }
                for(int k=1;k<=9;k++){
                    b[a[i][1]][a[i][2]][(a[i][3]+10-k)%10][(a[i][4]+10-k)%10][a[i][5]]++;
                }
            }else if(j==4){
                for(int k=0;k<=9;k++){
                    if(k==a[i][j])continue;
                    b[a[i][1]][a[i][2]][a[i][3]][k][a[i][5]]++;
                }
                for(int k=1;k<=9;k++){
                    b[a[i][1]][a[i][2]][a[i][3]][(a[i][4]+10-k)%10][(a[i][5]+10-k)%10]++;
                }
            }else if(j==5){
                for(int k=0;k<=9;k++){
                    if(k==a[i][j])continue;
                    b[a[i][1]][a[i][2]][a[i][3]][a[i][4]][k]++;
                }
            }
        }
    }
    for(int c=0;c<=9;c++)for(int d=0;d<=9;d++)for(int e=0;e<=9;e++)for(int f=0;f<=9;f++)for(int g=0;g<=9;g++)if(b[c][d][e][f][g]==n)ans++;
    printf("%d",ans);
    return 0;
}
