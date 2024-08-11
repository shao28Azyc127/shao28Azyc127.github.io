#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
int n,ans,a[maxn],pw[maxn];
void init()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        for(int j=1;j<=5;j++) cin>>x,a[i]=a[i]*10+x;
    }
    pw[0]=1;
    for(int i=1;i<=6;i++) pw[i]=pw[i-1]*10;
}
void work()
{
    for(int i=0;i<=99999;i++)
    {
        int num=0;
        for(int j=1;j<=n;j++)
        {
            int cnt=0;
            for(int k=1;k<=5;k++)
            {
                int x=i/pw[k-1]%10;
                int y=a[j]/pw[k-1]%10;
                if(x!=y) cnt++;
            }
            if(cnt==1)
            {
                num++;
                continue;
            }
            if(cnt>2 || cnt==0) break;
            int pre=0,val1,val2;
            for(int k=1;k<=5;k++)
            {
                int x=i/pw[k-1]%10;
                int y=a[j]/pw[k-1]%10;
                if(x!=y)
                {
                    if(!pre) 
                    {
                        pre=k;
                        val1=(x-y+10)%10;
                        val2=(y-x+10)%10;
                        continue;
                    }
                    else if(pre+1!=k) break;
                    int val3=(x-y+10)%10;
                    int val4=(y-x+10)%10;
                    if(val1==val3 || val2==val4) num++;
                    else break;
                }
            }
        }
        if(num==n) 
        {
            ans++;
            // cout<<i<<endl;
        }
    }
    printf("%d\n",ans);
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    init();
    work();
    return 0;
}