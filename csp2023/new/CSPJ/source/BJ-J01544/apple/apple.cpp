#include <bits/stdc++.h>
using namespace std;
long long days=0,last;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    bool b=0;
    long long n;cin>>n;
    while(n>0){
        days++;
        long long x=(n-1)/3+1;
        if((n-1)%3==0&&b==0){b=1;last=days;}
        n-=x;
    }cout<<days<<' '<<last<<endl;
}
