#include<bits/stdc++.h>
using namespace std;
bool v[1000001];
int n,f;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int flag=-1;
        for(int j=1;j<=n;j++)
        {
            if(v[j]==false)
            {
                flag=j;
                break;
            }
        }
        if(flag==-1)
        {
            cout<<i-1<<" "<<f;
            return 0;
        }
        int gs=0;
        for(int j=flag;j<=n;j++)
        {
            if(v[j]==false)
            {
                if(gs%3==0)
                {
                    v[j]=true;
                    if(j==n) f=i;
                    gs=1;
                }
                else
                {
                    gs++;
                }
            }
        }
    }
    cout<<n<<" "<<f;
    return 0;
}
