#include <bits/stdc++.h>
using namespace std;

long long n;

long long f(long long a,long long b){
    if(a%b){
        return a/b+1;
    }
    else{
        return a/b;
    }
}

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    long long n2=n;
    int cnt=0;
    while(n2){
        n2-=f(n2,3);
        cnt++;
    }
    int i;
    for(i=1;n%3!=1;i++){
        n-=f(n,3);
    }
    cout<<i<<" "<<cnt;
    return 0;
}
