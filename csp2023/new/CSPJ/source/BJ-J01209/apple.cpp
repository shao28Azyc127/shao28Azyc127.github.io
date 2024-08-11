#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a[1000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int cnt=0,ans;
    for(int i=1;;i++)
    {
        int cnt2=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==0)
            {
                if(cnt2==0)
                {
                    a[j]=i;
                    cnt++;
                    if(cnt==n)
                    {
                        cout<<i<<' '<<a[n]<<endl;
                        return 0;
                    }
                }
                cnt2=(cnt2+1)%3;
            }
        }
    }
    return 0;
}
