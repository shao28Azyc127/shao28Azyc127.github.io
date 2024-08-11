#include <bits/stdc++.h>
using namespace std;
int main(){
    FILE* f=freopen("apple.in","r",stdin);
    FILE* f2=freopen("apple.out","w",stdout);
    long long n,ans=0,ans2=0,first=1;
    cin>>n;
    while(n){
        double d=n/3.0;
        int d2=ceil(d);
        ans++;
        if((n-1)%3==0&&first){
            ans2=ans;
            first=0;
        }
        n-=d2;
    }
    cout<<ans<<' '<<ans2;
    fclose(f);
    fclose(f2);
    return 0;
}
