#include<bits/stdc++.h>
using namespace std;
int h[10][10][10][10][10],a[10][10];
bool num(int sum1,int sum2,int x1,int x2){
    int h[10][10];
    memset(h,0,sizeof(h));
    while(h[sum1][sum2]==0){
        if(sum1==x1&&sum2==x2){
            return false;
        }
        h[sum1][sum2]++;
        sum1++;
        sum2++;
        sum1%=10;
        sum2%=10;
    }
    return true;
}
bool error(int i,int j,int k,int l,int m,int x){
    int sum[6]={0,i,j,k,l,m};
    int ans=0,id[10];
    memset(id,0,sizeof(id));
    for(int q=1;q<=5;q++){
        if(a[x][q]!=sum[q]){
            ans++;
            id[ans]=q;
        }
    }
    if(ans>=3||ans==0){
        return true;
    }
    if(ans==2&&(id[2]-id[1]!=1||num(sum[id[1]],sum[id[2]],a[x][id[1]],a[x][id[2]]))){
        return true;
    }
    return false;
}
void work(int id){
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    for(int m=0;m<=9;m++){
                        if(!error(i,j,k,l,m,id)){
                            h[i][j][k][l][m]++;
                        }
                    }
                }
            }
        }
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5]);
        work(i);
    }
    int ans=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    for(int m=0;m<=9;m++){
                        if(h[i][j][k][l][m]==n){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
