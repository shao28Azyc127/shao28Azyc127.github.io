#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,f,ans;
int last(int x,int c){
    if(x==0) return 0;
    if(x%3==1&&f==0){
        f=1;
        ans=c;
    }
    return last(x-(x+2)/3,c+1)+1;
}
signed main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int cnt=0,l;
    cin>>n;l=n;
    cout<<last(l,1)<<' '<<ans;
    return 0;
}
