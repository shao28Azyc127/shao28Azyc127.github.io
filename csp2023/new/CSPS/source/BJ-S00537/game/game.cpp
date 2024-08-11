#include<bits/stdc++.h>
using namespace std;
const int N=2E6+1,p=131;
string a;
bool Check(int x,int y)
{
    for(int i=x;i<=x+y>>1;i++)
        if(a[i-1]!=a[y-i])
            return false;
    return true;
}
int flag[N],tot=0;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,ans=0;
    cin>>n;

    cin>>a;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+2;j<=n;j++)
            if(Check(i,j))
            {
                ans++;
                tot++;
                for(int k=i;k<=j;k++)
                    flag[i]=tot;
                if((flag[i-1] && flag[j+1]!=flag[i-1]))
                {
                    int now=flag[i-1];
                    int p=i-1;
                    while(flag[p]==now && p>0)
                    {
                        flag[p--]=tot;
                    }
                    ans++;
                }
                if((flag[j+1] && flag[j+1]!=flag[i-1]))
                {
                    int now=flag[j+1];
                    int p=j+1;
                    while(flag[p]==now && p<n)
                    {
                        flag[p++]=tot;
                    }
                    ans++;
                }
            }
                
    }
    cout<<ans;
    return 0;
}