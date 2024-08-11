#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int ans1=0,ans2=0;
    while (n){
        ans1++;
        if ((n-1)%3==0&&ans2==0){
            ans2=ans1;
        }
        n-=(n+2)/3;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
