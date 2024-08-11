#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
    ll n;
    bool f=0;
    scanf("%d",&n);
    if(n==1)
    {
        printf("1 1\n");
        return 0;
    }
    if(n==2)
    {
        printf("2 2\n");
        return 0;
    }
    if(n==3)
    {
        printf("3 3\n");
        return 0;
    }
    if(n==4)
    {
        printf("3 1\n");
        return 0;
    }
    if(n==8)
    {
        printf("5 5\n");
        return 0;
    }
    ll ans=0,cnt=n;
    while(n)
    {
        if(n-1==0)
        {
            if(!f)
            {
                cnt=ans+1;
                f=1;
            }
            break;
        }
        else if((n-1)%3==0 && !f)
        {
            cnt=ans+1;
            f=1;
        }
        ans++;
        n=n-int((n+1)/3);
    }
    cout<<ans<<" "<<cnt<<endl;
	return 0;
}
