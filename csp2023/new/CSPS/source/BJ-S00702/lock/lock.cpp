#include <bits/stdc++.h>
using namespace std;
bool cor1[10][10][10][10][10];
bool cor2[10][10][10][10][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;scanf("%d",&n);
    memset(cor1,1,sizeof(cor1));
    for(int i=0;i<n;i++){
        int a,b,c,d,e;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        for(int i=1;i<10;i++)cor2[(a+i)%10][b][c][d][e]=1;
        for(int i=1;i<10;i++)cor2[a][(b+i)%10][c][d][e]=1;
        for(int i=1;i<10;i++)cor2[a][b][(c+i)%10][d][e]=1;
        for(int i=1;i<10;i++)cor2[a][b][c][(d+i)%10][e]=1;
        for(int i=1;i<10;i++)cor2[a][b][c][d][(e+i)%10]=1;
        for(int i=1;i<10;i++)cor2[(a+i)%10][(b+i)%10][c][d][e]=1;
        for(int i=1;i<10;i++)cor2[a][(b+i)%10][(c+i)%10][d][e]=1;
        for(int i=1;i<10;i++)cor2[a][b][(c+i)%10][(d+i)%10][e]=1;
        for(int i=1;i<10;i++)cor2[a][b][c][(d+i)%10][(e+i)%10]=1;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    for(int l=0;l<10;l++){
                        for(int r=0;r<10;r++){
                            cor1[i][j][k][l][r]&=cor2[i][j][k][l][r];
                            cor2[i][j][k][l][r]=false;
                        }
                    }
                }
            }
        }
    }int ans=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                for(int l=0;l<10;l++){
                    for(int r=0;r<10;r++){
                        ans+=cor1[i][j][k][l][r];
                    }
                }
            }
        }
    }cout<<ans;
    return 0;
}
