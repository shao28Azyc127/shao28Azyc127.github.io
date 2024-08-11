#include<bits/stdc++.h>
using namespace std;
long long n,ans1,ans2;
bool b[1010100];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    long long temp=n;
    while(temp!=0)
    {
        long long g=temp*2;
        g/=3;
        temp=g;
        ans1++;
    }
    cout<<ans1<<" ";
    if(n>1e6)
    {
        cout<<ans1-3;
        return 0;
    }
    for(int i=1;i<=n;i++) b[i]=1;
    long long temp2=n,gh=1;
    while(1)
    {
        ans2++;
        gh=1;
        for(int i=1;i<=n;i++)
        {
            //cout<<i<<" "<<gh<<endl;
            if(!b[i]) continue;
            if(gh%3==1)
            {
                b[i]=0;
                if(i==n)
                {
                    cout<<ans2;
                    return 0;
                }
            }
            gh++;

        }
    }
    return 0;
}

