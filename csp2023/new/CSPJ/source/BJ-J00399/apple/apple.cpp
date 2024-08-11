#include<bits/stdc++.h>
using namespace std;
int n,n0,book[1000010],cnt;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    int n0=n,k=0;
    while(n0){
        k++;
        cnt=0;
        for(int j=1;j<=n;j++){
            if(book[j]) continue;
            if(!cnt) book[j]=k,n0--;
            cnt=(cnt+1)%3;
        }
    }
    printf("%d %d",k,book[n]);

    return 0;
}
