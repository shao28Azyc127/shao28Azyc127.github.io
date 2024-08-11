#include<bits/stdc++.h>
using namespace std;
int a,jg1,jg2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&a);
    while(a!=0&&a%3!=1) jg1++,jg2++,a-=(a+2)/3;
    while(a!=0) jg1++,a-=(a+2)/3;
    printf("%d %d\n",jg1,jg2+1);
    return 0;
}