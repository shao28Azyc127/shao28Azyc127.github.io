#include<iostream>
#include<queue>
using namespace std;
int day=1,ans=1;
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int maxday=-1;
    for(int i=1;i<=n;i++){
        day=1;
        int a=i;
        while(a%3!=1){
            a-=(a+2)/3;
            day++;
        }
        maxday=max(maxday,day);
    }
    while(n%3!=1){
        n-=(n+2)/3;
        ans++;
    }
    cout<<maxday<<' '<<ans;
    return 0;
}
