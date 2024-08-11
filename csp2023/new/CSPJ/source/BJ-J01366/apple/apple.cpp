#include<iostream>
#include<queue>
using namespace std;
int n,a1,a2;
bool h[1000000010];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) h[i]=1;
    while(1)
    {
        a1++;
        int t=0;
        for(int i=1;i<=n;i++)
        {
            if(h[i]==1)
            {
                if(t==0)
                {
                    h[i]=0;
                    if(i==n) a2=a1;
                    t=2;
                }
                else t--;
            }
        }
        bool flag=0;
        for(int i=1;i<=n;i++) if(h[i]==1) flag=1;
        if(flag==0) break;
    }
    cout<<a1<<' '<<a2;
    return 0;
}
