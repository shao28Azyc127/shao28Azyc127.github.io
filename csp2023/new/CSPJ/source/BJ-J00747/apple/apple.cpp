#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen ("apple.in","r",stdin);
    freopen ("apple.out","w",stdout);
    long long n;
    scanf ("%d",&n);
    long long k=0,a=0;
    while (n>0){
        k++;
        if (n%3==1&&a==0){
            a=k;
        }
        n-=(n+2)/3;
    }
    printf ("%lld %lld",k,a);
    return 0;
}
