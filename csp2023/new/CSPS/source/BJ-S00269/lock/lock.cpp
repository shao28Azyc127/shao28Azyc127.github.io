#include<bits/stdc++.h>
using namespace std;
const int MAXN=10;
int n;
int a[MAXN][MAXN],flag[MAXN];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(n==1)    printf("81");
    else if(n==2){
        int k=0;
        for(int i=1;i<=5;i++){
            if(a[1][i]!=a[2][i]){
                flag[++k]=i;
            }
        }
        if(k>=3)    printf("0");
        else{
            if(k==0)    printf("81");
            else if(k==1)    printf("10");
            else{
                if(a[1][flag[1]]-a[2][flag[1]]==a[1][flag[2]]-a[2][flag[2]])    printf("10");
                else    printf("2");
            }
        }
    }
    else{
        int k=0;
        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int x=1;x<=5;x++){
                        if(a[i][x]!=a[j][x] || a[i][x]!=a[k][x] || a[j][x]!=a[k][x])    flag[x]++;
                    }
                }
            }
        }
        for(int i=1;i<=5;i++){
            if(flag[i]!=0)  k++;
        }
        if(k>=3)    printf("0");
        else{
            if(k==1)    printf("%d",10-n);
            else printf("1");
        }
    }
    return 0;
}
