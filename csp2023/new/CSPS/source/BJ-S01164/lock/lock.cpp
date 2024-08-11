#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
long long n,a,b,c,d,e,i,j,k,l,p,f[12][12][12][12][12],sum=0;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
        scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
        for(j=1;j<=9;j++){
            f[(a+j)%10][b][c][d][e]++;
            f[a][(b+j)%10][c][d][e]++;
            f[a][b][(c+j)%10][d][e]++;
            f[a][b][c][(d+j)%10][e]++;
            f[a][b][c][d][(e+j)%10]++;
        }
        for(j=1;j<=9;j++){
            f[(a+j)%10][(b+j)%10][c][d][e]++;
            f[a][(b+j)%10][(c+j)%10][d][e]++;
            f[a][b][(c+j)%10][(d+j)%10][e]++;
            f[a][b][c][(d+j)%10][(e+j)%10]++;
        }
    }
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            for(k=0;k<10;k++){
                for(l=0;l<10;l++){
                    for(p=0;p<10;p++){
                        if(f[i][j][k][l][p]==n){
                            sum++;
                        }
                    }
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
