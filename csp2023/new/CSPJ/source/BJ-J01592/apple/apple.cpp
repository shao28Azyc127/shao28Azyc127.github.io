#include<iostream>
#include<cstdio>
using namespace std;
int n,cnt;
int ans1=0,ans2=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    cnt=n;
    while(cnt>0){
        cnt-=(cnt+2)/3;
        ans1++;
    }
    int x=n;
    while(x%3!=1){
        x=x-((x+1)/3);
        ans2++;
    }
    ans2+=1;
    cout<<ans1<<" "<<ans2;

    return 0;
}
