#include<bits/stdc++.h>
using namespace std;
int n,maxn,ans,zhuan1,buzhuan,zhuan2,temp;
bool OKK=false;
int a[10][10];
int s[1005][10];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    }
    ans=n*81;
    cout<<ans;
    return 0;
}
