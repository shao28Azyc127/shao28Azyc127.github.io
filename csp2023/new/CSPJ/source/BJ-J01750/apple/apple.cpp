#include<bits/stdc++.h>
using namespace std;
long long n;//given apples
long long cnt;//the number of apples now
long long a;//this days' apple;
long long day;//days needed
long long ans;//the day the n apple was picked
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    cnt=n;a=n;
    for(int i=1;i<=n;i++){
        if(cnt==0) break;
        else day++;
        for(int j=1;j<=a;j++){
            if(j%3==1) cnt-=1;
            if(j%3==1 && j==a && ans==0) ans=day;
        }
        a=cnt;
    }

    cout<<day<<" "<<ans;
    return 0;
}
