#include<bits/stdc++.h>
using namespace std;
int a[100000010];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    int m=n;
    while(m>0)
    {
        cnt++;
        int cnt0=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                cnt0++;
                if(cnt0%3==1)
                {
                    a[i]=cnt;
                    m--;
                }

            }
        }
    }
    cout<<cnt<<' '<<a[n];
}
