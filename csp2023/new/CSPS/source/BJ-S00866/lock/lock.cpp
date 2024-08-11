#include <bits/stdc++.h>

using namespace std;

int n, kk[10][5],ans[100050],num=0;
int a,b,c,d,e;
int oot=0;

int poww(int nu, int ti){
    int k=1;
    for(int i=0;i<ti;i++)
        k*=nu;
    return k;
}

int summ(int level){
    return kk[level][4]*poww(10,4)+kk[level][3]*poww(10,3)+kk[level][2]*poww(10,2)+kk[level][1]*poww(10,1)+kk[level][0]*poww(10,0);
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    memset(ans,0,sizeof(ans)); memset(kk,0,sizeof(kk));
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=4;j>=0;j--){
            scanf("%d",&kk[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=4;j>=0;j--){
            for(int tim=1;tim<10;tim++){
                kk[i][j]++;
                kk[i][j]=kk[i][j]%10;
                ans[summ(i)]++;
            }
            kk[i][j]++; kk[i][j]=kk[i][j]%10;
            if(j!=0){
                for(int tim=1;tim<10;tim++){
                    kk[i][j]++;
                    kk[i][j]=kk[i][j]%10;

                    kk[i][j-1]++;
                    kk[i][j-1]=kk[i][j-1]%10;
                    ans[summ(i)]++;

                }
                kk[i][j]++; kk[i][j-1]++;
                kk[i][j]=kk[i][j]%10; kk[i][j-1]=kk[i][j-1]%10;
            }

        }
        ans[summ(i)]=0;
    }

    for(int i=0;i<100050;i++){
        if(ans[i]==n)
            oot++;
    }
    printf("%d",oot);
    return 0;
}
