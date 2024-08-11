#include <bits/stdc++.h>
using namespace std;
int n,ans;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    for(int i=1;i<=n;i++)
    {
        int t1,t2,t3;\
        int t=0,j=0;
        cin>>t1>>t2>>t3;
        while(t<t1)
        {
            j++;
            t+=max(t2+t3*j,1);
        }
        ans=max(ans,j);
    }
    for(int i=1;i<=n-1;i++)
    {
        int t1,t2;
        cin>>t1>>t2;

    }
    cout<<ans;
    return 0;
}
