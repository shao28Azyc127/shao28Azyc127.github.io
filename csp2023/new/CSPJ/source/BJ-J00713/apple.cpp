#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    int n;
    cin>>n;
    int cnt=0,id=n;
    int day=0,ans=-1;
    while(cnt<n){
        day++;
        if((n-cnt)%3==0)cnt+=(n-cnt)/3;
        else cnt+=(n-cnt)/3+1;
        if(ans==-1&&id%3==1)ans=day;
        id=n-cnt;
    }
    cout<<day<<" "<<ans;
    return 0;
}
