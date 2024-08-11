#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    scanf("%d%d",&t,&m);
    int a[t+1],b[t+1],c[t+1];
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        if(m<=1&&b[i]==0&&c[i]==0){
            printf("%d",0);
        }
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
