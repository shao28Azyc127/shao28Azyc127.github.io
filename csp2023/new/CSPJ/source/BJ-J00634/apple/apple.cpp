#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
int a[1145];
int n;
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);


    cin>>n;
    int day = 0,ans=0; bool f=1;
    while(n) {
        if(n%3==1 && f) ans=day+1,f=0;
        if(n<=3) n--;
        else {
            if(n%3==0) n=n-n/3;
            else       n=n-n/3-1;
        }
        ++day;
    }
    cout<<day<<' '<<ans<<endl;
    return 0;
}
