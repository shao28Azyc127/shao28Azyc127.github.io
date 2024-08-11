#include<iostream>
#include<cstdint>
#include<cstdio>
using namespace std;

int ans1=0;
int ans2=INT32_MAX;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int x=n;
    while(x){
        if(x%3==1){
            ans2=min(ans2,ans1+1);
        }
        ans1++;
        int m=(x+2)/3;
        x=x-m;
    }

    cout<<ans1<<' '<<ans2<<endl;

    return 0;
}