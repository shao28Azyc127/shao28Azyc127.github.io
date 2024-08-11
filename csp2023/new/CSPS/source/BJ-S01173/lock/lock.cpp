#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
int c[10],k;
bool t(int t1,int t2){
    for(int i=1;i<=n;i++){
        int x1=(a[i][c[1]]-t1+10)%10;
        int x2=(t1-a[i][c[1]]+10)%10;
        int x3=(a[i][c[1]+1]-t2+10)%10;
        int x4=(t2-a[i][c[1]+1]+10)%10;
        if((x1!=x3&&x2!=x4)||(x1==0&&x2==0&&x3==0&&x4==0)){
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
            if(i>1&&a[i][j]!=a[i-1][j]){
                c[++k]=j;
            }
        }
    }
    if(k==0){
        printf("81");
        return 0;
    }
    if(k==1){
        printf("10");
        return 0;
    }
    if(k==2){
        int cnt=0;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
               cnt+=t(i,j);
            }
        }
        printf("%d",cnt);
        return 0;
    }
    if(k>=3){
        printf("0");
        return 0;
    }
    return 0;
}
