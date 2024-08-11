#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ans2=1e9;
    cin>>n;
    int m=n;
    if(n==1){
        cout<<1<<" "<<1;
        return 0;
    }
    if(n%3==1){
        ans2=1;
    }
    int t=0;
    while(m>0){
        int temp;
        t++;
        if(m%3==0){
            temp=m/3;
        }
        else{
            temp=m/3+1;
        }
        if(n%3==1){
            ans2=min(ans2,t);
        }
        else n-=temp;
        ans1++;
        m-=temp;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
