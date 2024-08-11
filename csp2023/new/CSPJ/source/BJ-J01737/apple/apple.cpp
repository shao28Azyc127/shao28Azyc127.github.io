#include <bits/stdc++.h>
using namespace std;
int n;
int d;
int f(int n,int x){
    int s=(n+2)/3;
    if(d==0&&(n-1)%3==0)
        d=x;
    n-=s;
    if(n==0) return x;
    return f(n,x+1);
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    printf("%d",f(n,1));
    printf(" %d",d);
}
