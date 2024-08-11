#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,m=1,i=1;
    scanf("%d",&n);
    for(;m<n;i++){
        m+=i;
        //printf("Chtholly %d %d\n",m,i);
    }
    printf("%d 1",i);
    return 0;
}
