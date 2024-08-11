#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans,cnt;
    cin>>n;
    int k=n,f=0;
    for(int i=1;i<=k;i++)
    {

        if(n%3==1&&f==0)
        {
            ans=i;
            f=1;
        }

        if(n==1)
        {
            cnt=i;
            break;
        }
        if(n%3==0)
            n=n-n/3;
        else
            n=n-n/3-1;
    }

    cout << cnt <<" "<< ans<<endl;
    return 0;
}
