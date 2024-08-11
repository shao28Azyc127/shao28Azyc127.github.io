#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,s=1,ss=0;
    bool j=0;
    scanf("%d",&n);
    while(n>0){
        int x=n/3+1;
        if(j!=1){
            if((n-1)%3==0){
                ss=s;
                j=1;
            }
        }
        s++;
        n-=x;
    }
    printf("%d %d",s,ss);

    return 0;
}

