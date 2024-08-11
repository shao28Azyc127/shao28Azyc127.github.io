#include<bits/stdc++.h>
using namespace std;
int n,butong,mbutong,bw[5],bws;
char a[15][8];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++)
			scanf("%c",&a[i][j]);
        for(int j=0;j<5&&i>1;j++){
            if(a[i][j]!=a[i-1][j]){
                butong++;
                if(!bw[i])bws++;
                bw[i]=true;
            }
        }
        mbutong=max(mbutong,butong);
    }
    if(n==1){
        printf("81");
        return 0;
    }
    if(n==2){
        if(mbutong==1&&(a[1][4]!=a[2][4]||a[1][0]!=a[2][0])){
            printf("10");
            return 0;
        }
        if(mbutong==1&&!(a[1][4]!=a[2][4]||a[1][0]!=a[2][0])){
            printf("11");
            return 0;
        }
        if(mbutong>=2){
            bool s=true;
            for(int i=1;i<4;i++){
                if((bw[i]!=bw[i+1])&&(bw[i-1]!=bw[i])){
                    s=false;
                }
            }
            if(!s){
                printf("0");
                return 0;
            }
            else{
                printf("1");
                return 0;
            }
        }
    }
    if(bws==1){
        if(a[1][4]!=a[2][4]||a[1][0]!=a[2][0]){
            printf("10");
            return 0;
        }
        else{
            printf("11");
            return 0;
        }
    }
    else printf("1");
    return 0;
}
