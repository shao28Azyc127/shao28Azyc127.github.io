#include<bits/stdc++.h>
using namespace std;
int n;
int a,b,c,d,e;
int f[12][12][12][12][12];
int cnt;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        for(int j=1;j<=9;j++){
            int x=(a+j)%10;
            f[x][b][c][d][e]++;
        }
        for(int j=1;j<=9;j++){
            int x=(b+j)%10;
            f[a][x][c][d][e]++;
        }
        for(int j=1;j<=9;j++){
            int x=(c+j)%10;
            f[a][b][x][d][e]++;
        }
        for(int j=1;j<=9;j++){
            int x=(d+j)%10;
            f[a][b][c][x][e]++;
        }
        for(int j=1;j<=9;j++){
            int x=(e+j)%10;
            f[a][b][c][d][x]++;
        }

        for(int j=1;j<=9;j++){
            int x=(a+j)%10,y=(b+j)%10;
            f[x][y][c][d][e]++;
        }
        for(int j=1;j<=9;j++){
            int x=(b+j)%10,y=(c+j)%10;
            f[a][x][y][d][e]++;
        }
        for(int j=1;j<=9;j++){
            int x=(c+j)%10,y=(d+j)%10;
            f[a][b][x][y][e]++;
        }
        for(int j=1;j<=9;j++){
            int x=(d+j)%10,y=(e+j)%10;
            f[a][b][c][x][y]++;
        }
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    for(int o=0;o<=9;o++){
                        if(f[i][j][k][l][o]==n) cnt++;
                    }
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}