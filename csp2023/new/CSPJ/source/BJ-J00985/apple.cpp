#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    int q=1;
    int t=0,p;
    long long o=n;
    while(n!=0){
        t++;
        long long k=(n-1)/3+1;
        if((n-1)%3==0&&q==1) p=t,q=0;
        n-=k;
    }
    cout<<t<<" "<<p<<"\n";
    return 0;
}
