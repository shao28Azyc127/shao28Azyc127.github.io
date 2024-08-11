#include <bits/stdc++.h>
using namespace std;
int n,i,ans;
int main(){
        freopen("apple.in","r",stdin);
        freopen("apple.out","w",stdout);
        scanf("%d",&n);
        for(i=1;n>0;i++){
                if(n%3==1){
                        ans=i;
                        break;
                }
                n-=(n+2)/3;
        }
        for(;n>0;i++){
                n-=(n+2)/3;
        }
        printf("%d %d",i-1,ans);
        fclose(stdin);
        fclose(stdout);
        return 0;
}