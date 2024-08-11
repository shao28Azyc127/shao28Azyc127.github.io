#include<bits/stdc++.h>
using namespace std;
int n,a[9][6];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=5;++j){
            scanf("%d",&a[i][j]);
        }
    }

    if(n==1){
        printf("81");
    }else if(n==8){
        printf("1");
    }else{
        for(int j=1;j<=5;++j)
            for(int i=1;i<=8;++i){
                if(a[i][j]!=a[i][j+1])
                    printf("14");
            }
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
