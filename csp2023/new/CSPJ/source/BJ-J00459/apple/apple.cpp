#include<bits/stdc++.h>
using namespace std;
int n;
int ans,cnt,ans2,m,cnt2,ans1;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    while(m){
        ans1++;
        if(m%3!=0){
            cnt=m/3+1;
            if(m%3==1){
            ans2=ans1;
            break;
        }
        }
        else cnt=m/3;
        m-=cnt;
    }
    while(n){
        ans++;
        if(n%3!=0){
            cnt2=n/3+1;
        }
        else cnt2=n/3;
        n-=cnt2;
    }
    cout<<ans<<" "<<ans2<<endl;
    return 0;
}

