#include<bits/stdc++.h>
using namespace std;
struct num
{
    int id,val;
    bool f;
}a[1000001];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i].id=a[i].val=i;
        a[i].f=1;
    }
    int cnt=0,ans;
    while(1)
    {
        cnt++;
        int cur=0,t=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i].f)
            {
                t++;
                if(a[i].id%3==1)
                {
                    if(a[i].val==n)ans=cnt;
                    a[i].f=0;
                }
                else
                {
                    cur++;
                    a[i].id=cur;
                }
            }
        }
        if(t==0)break;
    }
    cout<<cnt-1<<" "<<ans;
    return 0;
}