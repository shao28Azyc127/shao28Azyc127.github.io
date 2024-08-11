#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int t=n;
    int sum=0;
    int ans=0;
    while(t){
        sum++;
        if((t-1)%3==0&&!ans){
            ans=sum;
        }
        t-=ceil(t/3.0);

    }
    cout<<sum<<" "<<ans<<endl;
    return 0;
}
