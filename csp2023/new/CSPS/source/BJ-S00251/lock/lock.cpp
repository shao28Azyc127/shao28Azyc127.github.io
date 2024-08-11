#include<bits/stdc++.h>
using namespace std;
int a[100050],b[10][10],c[10]={1,10,100,1000,10000,100000},d[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&b[i][j]);
            d[i]*=10;
            d[i]+=b[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            for(int k=1;k<=9;k++){
                int t=d[i]+k*c[5-j];
                if(b[i][j]+k>=10){
                    t-=c[6-j];
                }a[t]++;
                if(a[t]==n) ans++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++){
            for(int k=1;k<=9;k++){
                int t=d[i]+k*c[5-j];
                if(b[i][j]+k>=10){
                    t-=c[6-j];
                }
                t+=k*c[4-j];
                if(b[i][j+1]+k>=10){
                    t-=c[5-j];
                }
                a[t]++;
                if(a[t]==n) ans++;
            }
        }
    }printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
