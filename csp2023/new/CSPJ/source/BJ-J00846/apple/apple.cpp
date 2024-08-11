#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    long long i=0;
    long long m=0;
    while(n!=1){
        i++;
        int x=n%3;
        if(x==1&&m==0)m=i;
        if(x==0)n=n/3*2;
        else n=n/3*2+x-1;
    }
    if(m==0)m=i+1;
    cout<<i+1<<" "<<m;
    return 0;
}
