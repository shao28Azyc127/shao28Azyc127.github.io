#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >>n;
    bool flag=0;
    long long day=0,sum=0;
    while(n>0){
        if(flag==0) day++;
        sum++;
        if(n%3==1) flag=1;
        int q=n/3;
        int l=n%3;
        if(l!=0) q++;
        n-=q;
    }
    cout <<sum <<" " <<day <<'\n';
    return 0;
}
