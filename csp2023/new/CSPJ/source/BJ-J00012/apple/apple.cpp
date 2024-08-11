#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool b[100000050];
int f(int x)
{
    int cnt=0;
    while(x%3==0) x/=3,cnt++;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=0,nx,y=0;
    cin>>n;
    nx=n;
    while(nx)
    {
        nx-=int(ceil(nx/3.0));
        cnt++;

    }
    cout<<cnt<<" ";
    if(n%3==1) cout<<1;
    else if(n%3==2) cout<<cnt;
    else
    {
        while(b[n]==0)
        {
            int s=0;
            for(int i=1;i<=n;i++)
            {
                if(b[i]) continue;
                s++;
                if(s%3==1) b[i]=1;
            }
            y++;
        }
        cout<<y;
    }
    return 0;
}
