#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,ans,cnt,flg;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    k=n;
    while(k)
    {
        ans++;
        if(flg==0&&(k-1)%3==0){
            flg=1;
            cnt=ans;
        }
        k-=1;
        k-=k/3;
    }
    cout<<ans<<" "<<cnt;

    return 0;
}
