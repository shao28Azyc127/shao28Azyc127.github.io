#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,v=1,k = 2,cc,i,j,e = 0;
    scanf("%d",&n);
    int aa[n+5] = {0};
    for(i = 1;i <= n;i ++){
    e ++;
    v = 0;
        for(j = 1;j <= n;j ++){
            if(aa[j] == 1){}else{
                v = 1;
            }
            if(aa[j] == 0){
                if(k == 2){
                    if(j == n){
                        cc= e;
                    }
                    aa[j] = 1;
                    k = 0;
                }
                else{
                    k ++;
                }
            }
        }
        k = 2;
        if(v == 0){
            break;
        }
    }
    printf("%d %d",e-1,cc);
    return 0;
}
