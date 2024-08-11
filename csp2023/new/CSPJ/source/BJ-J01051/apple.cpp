#include<bits/stdc++.h>
using namespace std;
int f(int n){
    if(n<=3)return n;
    int x=n/3;
    bool r=n%3;
    int ji=x+r;
    return f(n-ji)+1;
}
int g(int n){
    if(n%3==1)return 1;
    int x=n/3;
    bool r=n%3;
    int ji=x+r;
    return g(n-ji)+1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;scanf("%d",&n);
    printf("%d %d",f(n),g(n));
    return 0;
}
