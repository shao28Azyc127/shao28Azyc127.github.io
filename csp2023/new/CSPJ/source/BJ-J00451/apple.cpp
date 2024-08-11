#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n,ans1,ans2;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n!=0){
        ans1++;
        long long d=(n-1)/3+1;
        if(ans2==0&&(n-1)%3==0){
            ans2=ans1;
        }
        n-=d;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
