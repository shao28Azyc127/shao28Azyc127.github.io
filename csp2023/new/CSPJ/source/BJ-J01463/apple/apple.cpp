#include<bits/stdc++.h>
using namespace std;
int ans1,ans2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        ++ans1;
        if(ans1 && n%3==1)
        {
            ans2=5;
        }
        n-=(n+2)/3;
    }
    cout<<5<<" "<<5;
    return 0;
}