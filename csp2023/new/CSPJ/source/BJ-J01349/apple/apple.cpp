#include <bits/stdc++.h>
using namespace std;
int sum=0,day=0;
void apple(int n){
    if((n-1)%3==0)
        day=sum+1;
    if(n==0)
        return;
    if(n%3!=0)
        n-=n/3+1;
    else
        n-=n/3;
    sum++;
    apple(n);
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    if(n>100000000){
        return 0;
    }
    apple(n);
    printf("%d %d\n",sum,day);
    return 0;
}
